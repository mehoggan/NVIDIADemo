#include "nvidia_demo/textures.h"

#include "nvidia_demo/resource_loader.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

std::size_t Textures::total_images_ = 0;

Textures::ImageConfigi::ImageConfigi(
  const ParameterName &pname,
  const int &param) :
  pname_(pname),
  param_(param)
{
  // TODO: Apply validation
}

GLenum Textures::ImageConfigi::gl_pname() const
{
  switch (pname_) {
  case ParameterName::DEPTH_STENCIL_TEXTURE_MODE: {
    return GL_DEPTH_STENCIL_TEXTURE_MODE;
  }
  case ParameterName::TEXTURE_BASE_LEVEL: {
    return GL_TEXTURE_BASE_LEVEL;
  }
  case ParameterName::TEXTURE_COMPARE_FUNC: {
    return GL_TEXTURE_COMPARE_FUNC;
  }
  case ParameterName::TEXTURE_COMPARE_MODE: {
    return GL_TEXTURE_COMPARE_MODE;
  }
  case ParameterName::TEXTURE_LOD_BIAS: {
    return GL_TEXTURE_LOD_BIAS;
  }
  case ParameterName::TEXTURE_MIN_FILTER: {
    return GL_TEXTURE_MIN_FILTER;
  }
  case ParameterName::TEXTURE_MAG_FILTER: {
    return GL_TEXTURE_MAG_FILTER;
  }
  case ParameterName::TEXTURE_MIN_LOD: {
    return GL_TEXTURE_MIN_LOD;
  }
  case ParameterName::TEXTURE_MAX_LOD: {
    return GL_TEXTURE_MAX_LOD;
  }
  case ParameterName::TEXTURE_MAX_LEVEL: {
    return GL_TEXTURE_MAX_LEVEL;
  }
  case ParameterName::TEXTURE_SWIZZLE_R: {
    return GL_TEXTURE_SWIZZLE_R;
  }
  case ParameterName::TEXTURE_SWIZZLE_G: {
    return GL_TEXTURE_SWIZZLE_G;
  }
  case ParameterName::TEXTURE_SWIZZLE_B: {
    return GL_TEXTURE_SWIZZLE_B;
  }
  case ParameterName::TEXTURE_SWIZZLE_A: {
    return GL_TEXTURE_SWIZZLE_A;
  }
  case ParameterName::TEXTURE_WRAP_S: {
    return GL_TEXTURE_WRAP_S;
  }
  case ParameterName::TEXTURE_WRAP_T: {
    return GL_TEXTURE_WRAP_T;
  }
  case ParameterName::TEXTURE_WRAP_R: {
    return GL_TEXTURE_WRAP_R;
  }
  }

  throw std::runtime_error("Unsupported texture parameter.");
}

const Textures::ParameterName &Textures::ImageConfigi::pname() const
{
  return pname_;
}

const int &Textures::ImageConfigi::param() const
{
  return param_;
}

Textures::ImageConfigf::ImageConfigf(
  const ParameterName &pname,
  const float &param) :
  pname_(pname),
  param_(param)
{
  // TODO: Apply validation
}

GLenum Textures::ImageConfigf::gl_pname() const
{
  switch (pname_) {
  case ParameterName::DEPTH_STENCIL_TEXTURE_MODE: {
    return GL_DEPTH_STENCIL_TEXTURE_MODE;
  }
  case ParameterName::TEXTURE_BASE_LEVEL: {
    return GL_TEXTURE_BASE_LEVEL;
  }
  case ParameterName::TEXTURE_COMPARE_FUNC: {
    return GL_TEXTURE_COMPARE_FUNC;
  }
  case ParameterName::TEXTURE_COMPARE_MODE: {
    return GL_TEXTURE_COMPARE_MODE;
  }
  case ParameterName::TEXTURE_LOD_BIAS: {
    return GL_TEXTURE_LOD_BIAS;
  }
  case ParameterName::TEXTURE_MIN_FILTER: {
    return GL_TEXTURE_MIN_FILTER;
  }
  case ParameterName::TEXTURE_MAG_FILTER: {
    return GL_TEXTURE_MAG_FILTER;
  }
  case ParameterName::TEXTURE_MIN_LOD: {
    return GL_TEXTURE_MIN_LOD;
  }
  case ParameterName::TEXTURE_MAX_LOD: {
    return GL_TEXTURE_MAX_LOD;
  }
  case ParameterName::TEXTURE_MAX_LEVEL: {
    return GL_TEXTURE_MAX_LEVEL;
  }
  case ParameterName::TEXTURE_SWIZZLE_R: {
    return GL_TEXTURE_SWIZZLE_R;
  }
  case ParameterName::TEXTURE_SWIZZLE_G: {
    return GL_TEXTURE_SWIZZLE_G;
  }
  case ParameterName::TEXTURE_SWIZZLE_B: {
    return GL_TEXTURE_SWIZZLE_B;
  }
  case ParameterName::TEXTURE_SWIZZLE_A: {
    return GL_TEXTURE_SWIZZLE_A;
  }
  case ParameterName::TEXTURE_WRAP_S: {
    return GL_TEXTURE_WRAP_S;
  }
  case ParameterName::TEXTURE_WRAP_T: {
    return GL_TEXTURE_WRAP_T;
  }
  case ParameterName::TEXTURE_WRAP_R: {
    return GL_TEXTURE_WRAP_R;
  }
  }

  throw std::runtime_error("Unsupported texture parameter.");
}

const Textures::ParameterName &Textures::ImageConfigf::pname() const
{
  return pname_;
}

const float &Textures::ImageConfigf::param() const
{
  return param_;
}

Textures::ImageWithConfig::ImageWithConfig(
  const std::string &relative_path,
  const std::vector<ImageConfigi> &configi,
  const std::vector<ImageConfigf> &configf) :
  relative_path_(relative_path),
  configi_(configi),
  configf_(configf)
{}

const std::string &Textures::ImageWithConfig::relative_path() const
{
  return relative_path_;
}

const std::vector<Textures::ImageConfigi> &
Textures::ImageWithConfig::configi() const
{
  return configi_;
}

const std::vector<Textures::ImageConfigf> &
Textures::ImageWithConfig::configf() const
{
  return configf_;
}

Textures::Textures(const std::vector<ImageWithConfig> &images)
{
  static int texture_units = 0;
  glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units);
  GL_CALL(glGetIntegerv);
  auto max_images = static_cast<unsigned long>(texture_units);
  if (total_images_ + images.size() > max_images) {
    throw std::runtime_error("Loaded too many textures.");
  }

  std::size_t image_num = 0;
  image_ids_.resize(images.size());
  for (std::size_t i = 0; i < images.size(); ++i) {
    const std::string &relative_path = images[i].relative_path();
    ResourceLoader::TextureInfo info;
    ResourceLoader::load_texture(relative_path, info);

    std::size_t expected = info.width * info.height *
      ResourceLoader::format_cardinality(info.format);
    if (info.image_bytes.size() != expected) {
      throw std::runtime_error("Invalid texture info returned from "
        "resource loader!!!\n" + info.to_string() + "\n");
    }

    // Create texture in OpenGL.
    glGenTextures(1, &image_ids_[image_num].id);
    GL_CALL(glGenTextures)

    image_ids_[image_num].active_id = static_cast<GLenum>(
      GL_TEXTURE0 + total_images_ + image_num);

    activate(image_num);

    std::cout << relative_path << " loaded with the following info: " << info
      << std::endl;

    glTexImage2D(
      GL_TEXTURE_2D,
      0,
      ResourceLoader::to_gl_format(info.format),
      info.width,
      info.height,
      0,
      ResourceLoader::to_gl_format(info.format),
      GL_UNSIGNED_BYTE,
      info.image_bytes.data());
    GL_CALL(glTexImage2D);

    for (const ImageConfigi &configi : images[i].configi()) {
      glTexParameteri(GL_TEXTURE_2D, configi.gl_pname(), configi.param());
      GL_CALL(glTexParameteri);
    }

    for (const ImageConfigf &configf : images[i].configf()) {
      glTexParameterf(GL_TEXTURE_2D, configf.gl_pname(), configf.param());
      GL_CALL(glTexParameterf);
    }

    ++image_num;
  }

  total_images_ += images.size();
}

Textures::~Textures()
{
  std::size_t image_num = 0;
  for (const Texture& texture : image_ids_) {
    activate(image_num);
    glDeleteTextures(1, &texture.id);
    ++image_num;
  }
}

void Textures::activate(std::size_t image_num) const
{
  glActiveTexture(image_ids_[image_num].active_id);
  GL_CALL(glActiveTexture)

  glBindTexture(GL_TEXTURE_2D, image_ids_[image_num].id);
  GL_CALL(glBindTexture)
}
