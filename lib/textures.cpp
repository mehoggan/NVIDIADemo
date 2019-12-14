#include "nvidia_demo/textures.h"

#include "nvidia_demo/resource_loader.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

std::size_t Textures::total_images_ = 0;

template <typename T>
Textures::ImageConfig<T>::ImageConfig(
  const ParameterName &pname,
  const T &param) :
  pname_(pname),
  param_(param)
{
  // TODO: Apply validation
}

template <typename T>
GLenum Textures::ImageConfig<T>::gl_pname() const
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

template <typename T>
const Textures::ParameterName &Textures::ImageConfig<T>::pname() const
{
  return pname_;
}

template <typename T>
const T &Textures::ImageConfig<T>::param() const
{
  return param_;
}

Textures::Textures(const std::vector<std::string> &relative_paths)
{
  static int texture_units = 0;
  glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units);
  GL_CALL(glGetIntegerv);

  if (total_images_ + relative_paths.size() >
    static_cast<unsigned long>(texture_units)) {
    throw std::runtime_error("Loaded too many textures.");
  }

  std::size_t image_num = 0;
  image_ids_.resize(relative_paths.size());
  for (std::size_t i = 0; i < relative_paths.size(); ++i) {
    const std::string &relative_path = relative_paths[i];
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

    // TODO: Take advantage of Parameters.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    ++image_num;
  }

  total_images_ += relative_paths.size();
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

template struct Textures::ImageConfig<int>;
template struct Textures::ImageConfig<float>;
