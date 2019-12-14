#include "nvidia_demo/resource_loader.h"

#include "nvidia_demo/gl_functions.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <utility>
#include <unordered_map>

#include <cstring>

#include <errno.h>
#include <png.h>
#include <stdlib.h>
#include <stdio.h>

std::string ResourceLoader::exe_path_;

namespace std
{
  template <>
  struct hash<opengl_core::gl_version>
  {
    std::size_t operator()(const opengl_core::gl_version& version) const
    {
      return ((hash<uint16_t>()(version.major)
        ^ (hash<uint16_t>()(version.minor) << 1)) >> 1);
    }
  };
}

namespace detail
{
  struct glsl_version
  {
    std::uint16_t major;
    std::uint16_t minor;

    std::string to_string() const
    {
      std::stringstream ss;
      ss << major << std::setw(2) << std::setfill('0') << minor;
      return ss.str();
    }
  };

  typedef std::unordered_map<opengl_core::gl_version, detail::glsl_version>
    ShaderVersionLookup_t;

  void load_png(
    const std::string &absolute_path,
    ResourceLoader::TextureInfo &out_info)
  {
    errno = 0;
    FILE *fp = fopen(absolute_path.c_str(), "rb");
    if (fp == nullptr) {
      throw std::runtime_error("Failed to load " + absolute_path +
        + " with ERROR: " + strerror(errno));
    }

    png_structp png = png_create_read_struct(
      PNG_LIBPNG_VER_STRING,
      nullptr,
      nullptr,
      nullptr);
    if (not png) {
      fclose(fp);
      throw std::runtime_error("Failed to init libpng for " + absolute_path);
    }

    png_infop info = png_create_info_struct(png);
    if(not info) {
      fclose(fp);
      png_destroy_read_struct(&png, &info, NULL);
      throw std::runtime_error("Failed to init libpng for " + absolute_path);
    }

    if (setjmp(png_jmpbuf(png))) {
      fclose(fp);
      png_destroy_read_struct(&png, &info, NULL);
      throw std::runtime_error("Failed to init libpng for " + absolute_path);
    }

    png_init_io(png, fp);

    png_read_info(png, info);

    int width = png_get_image_width(png, info);
    out_info.width = width;
    int height = png_get_image_height(png, info);
    out_info.height = height;
    png_byte bit_depth = png_get_bit_depth(png, info);
    out_info.bit_depth = bit_depth;
    png_byte color_type = png_get_color_type(png, info);

    if (bit_depth == 16) {
      png_set_strip_16(png);
    }

    if (color_type == PNG_COLOR_TYPE_PALETTE) {
      png_set_palette_to_rgb(png);
    }

    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) {
      png_set_expand_gray_1_2_4_to_8(png);
    }

    if (png_get_valid(png, info, PNG_INFO_tRNS)) {
      png_set_tRNS_to_alpha(png);
    }

    if (color_type == PNG_COLOR_TYPE_RGB ||
      color_type == PNG_COLOR_TYPE_GRAY ||
      color_type == PNG_COLOR_TYPE_PALETTE) {
      png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
    }
    out_info.format = ResourceLoader::TextureFormat::RGBA;

    if (color_type == PNG_COLOR_TYPE_GRAY ||
      color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
      png_set_gray_to_rgb(png);
    }

    png_read_update_info(png, info);

    png_bytep *row_pointers =
      (png_bytep *) malloc(sizeof(png_bytep) * height);
    const std::size_t row_bytes_count = png_get_rowbytes(png, info);
    for(int y = 0; y < height; ++y) {
      row_pointers[y] = (png_byte *) malloc(row_bytes_count);
    }

    out_info.image_bytes.clear();
    out_info.image_bytes.reserve(width * height * bit_depth);

    png_read_image(png, row_pointers);

    for (int row = 0; row < height; ++row) {
      for (std::size_t col = 0; col < row_bytes_count; ++col) {
        out_info.image_bytes.push_back(row_pointers[row][col]);
      }
    }

    errno = 0;
    int status = fclose(fp);
    if (status != 0) {
      std::cerr << "Failed to close " << absolute_path << " with: ERROR "
        << strerror(errno) << std::endl;
    }

    png_destroy_read_struct(&png, &info, NULL);

    for (int y= 0; y < height; ++y) {
      free(row_pointers[y]);
    }
    free(row_pointers);
  }
}

std::string ResourceLoader::format_to_string(const TextureFormat &format)
{
  switch (format) {
  case TextureFormat::RGB: return "RGB";
  case TextureFormat::RGBA: return "RGBA";
  }

  throw std::runtime_error("Unsupported opengl image format.");
}

std::string ResourceLoader::TextureInfo::to_string() const
{
  std::stringstream ss;
  ss << "TextureInfo: " << std::endl;
  ss << "Bytes (count " << image_bytes.size() << ")" << std::endl;
  ss << "Width: " << width << std::endl;
  ss << "Height: " << height << std::endl;
  ss << "Depth: " << bit_depth << std::endl;
  ss << "Format: " << ResourceLoader::format_to_string(format);
  return ss.str();
}

uint16_t ResourceLoader::format_cardinality(const TextureFormat &format)
{
  switch (format) {
  case TextureFormat::RGB: return 3u;
  case TextureFormat::RGBA: return 4u;
  }

  throw std::runtime_error("Unsupported opengl image format.");
}

GLenum ResourceLoader::to_gl_format(const TextureFormat &format)
{
  switch (format) {
  case TextureFormat::RGB: return GL_RGB;
  case TextureFormat::RGBA: return GL_RGBA;
  }

  throw std::runtime_error("Unsupported opengl image format.");
}

std::string ResourceLoader::load_shader(
  const std::string &name,
  const opengl_core::gl_version &version)
{
  static detail::ShaderVersionLookup_t lookup = {
    { {2, 0}, {1, 10} },
    { {2, 1}, {1, 20} },
    { {3, 0}, {1, 30} },
    { {3, 1}, {1, 40} },
    { {3, 2}, {1, 50} },
    { {3, 3}, {3, 30} },
    { {4, 0}, {4,  0} },
    { {4, 1}, {4, 10} },
    { {4, 2}, {4, 20} },
    { {4, 3}, {4, 30} },
    { {4, 4}, {4, 40} },
    { {4, 5}, {4, 50} },
    { {4, 5}, {4, 60} },
  };

  std::string glsl_ver = lookup[version].to_string();
  std::string absolute_path = exe_path_ + "/" +
    std::string("shaders/") + glsl_ver + "/" + name; 
  std::ifstream shader_file(absolute_path);

  if (not shader_file.good()) {
    throw std::runtime_error(std::string("Failed to load shader from ") +
      absolute_path);
  }

  auto ret = std::string((std::istreambuf_iterator<char>(shader_file)),
    std::istreambuf_iterator<char>());

  return ret;
}


void ResourceLoader::load_texture(
  const std::string &relative_path,
  TextureInfo &out_info)
{
  std::string absolute_path = exe_path_ + "/" + std::string("textures/")
    + relative_path;

  std::string extension = relative_path.substr(
    relative_path.find_last_of(".") + 1);
  std::transform(extension.begin(), extension.end(), extension.begin(),
    [](unsigned char c)
    {
      return std::tolower(c);
    }
  );

  if (extension.compare("png") == 0) {
    std::cout << "Going to load png from " << absolute_path << "..."
      << std::endl;
    detail::load_png(absolute_path, out_info);
  } else {
    throw std::runtime_error("Cannot load file type of " + extension);
  }
}

void ResourceLoader::exe_path(const std::string &pwd)
{
  exe_path_ = pwd;
}

const std::string &ResourceLoader::exe_path()
{
  return exe_path_;
}

std::ostream &operator<<(
  std::ostream &out,
  const ResourceLoader::TextureInfo &info)
{
  out << info.to_string();
  return out;
}
