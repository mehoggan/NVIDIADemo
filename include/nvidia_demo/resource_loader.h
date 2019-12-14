#ifndef RESOURCE_LOADER_H_INCLUDED
#define RESOURCE_LOADER_H_INCLUDED

#include <nvidia_demo/gl_functions.h>

#include <string>
#include <vector>

class ResourceLoader
{
public:
  enum class TextureFormat
  {
    RGB,
    RGBA
  };

  static std::string format_to_string(const TextureFormat &format);

  static uint16_t format_cardinality(const TextureFormat &format);

  struct TextureInfo
  {
    uint16_t width;
    uint16_t height;
    uint16_t bit_depth;
    TextureFormat format;
    std::vector<unsigned char> image_bytes;

    std::string to_string() const;
  };

  static GLenum to_gl_format(const TextureFormat &format);

public:
  static std::string load_shader(
    const std::string &name,
    const opengl_core::gl_version &version);

  static void load_texture(
    const std::string &relative_path,
    TextureInfo &out_info);

  static void exe_path(const std::string &pwd);

  static const std::string &exe_path();

private:
  static std::string exe_path_;
};

std::ostream &operator<<(
  std::ostream &out,
  const ResourceLoader::TextureInfo &info);

#endif
