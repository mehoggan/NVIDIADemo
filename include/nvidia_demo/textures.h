#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

#include <string>
#include <vector>

class Textures
{
public:
  struct Texture
  {
    GLuint id;
    GLenum active_id;
  };

  enum class ParameterName
  {
    DEPTH_STENCIL_TEXTURE_MODE,
    TEXTURE_BASE_LEVEL,
    TEXTURE_COMPARE_FUNC,
    TEXTURE_COMPARE_MODE,
    TEXTURE_LOD_BIAS,
    TEXTURE_MIN_FILTER,
    TEXTURE_MAG_FILTER,
    TEXTURE_MIN_LOD,
    TEXTURE_MAX_LOD,
    TEXTURE_MAX_LEVEL,
    TEXTURE_SWIZZLE_R,
    TEXTURE_SWIZZLE_G,
    TEXTURE_SWIZZLE_B,
    TEXTURE_SWIZZLE_A,
    TEXTURE_WRAP_S,
    TEXTURE_WRAP_T,
    TEXTURE_WRAP_R
  };

  template <typename T>
  struct ImageConfig
  {
  public:
    ImageConfig(const ParameterName &pname, const T &param);

    GLenum gl_pname() const;

    const ParameterName &pname() const;

    const T &param() const;

  private:
    ParameterName pname_;
    T param_;
  };

public:
  Textures(const std::vector<std::string> &relative_paths);

  ~Textures();

  Textures(const Textures &) = delete;

  Textures &operator=(const Textures &) = delete;

  Textures(Textures &&) = delete;

  Textures &operator=(Textures &&) = delete;

  void activate(std::size_t image_num) const;

private:
  std::vector<Texture> image_ids_;

private:
  static std::size_t total_images_;
};

#endif
