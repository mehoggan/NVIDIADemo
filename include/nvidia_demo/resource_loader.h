#ifndef RESOURCE_LOADER_H_INCLUDED
#define RESOURCE_LOADER_H_INCLUDED

#include <nvidia_demo/gl_functions.h>

#include <string>

class ResourceLoader
{
public:
  static std::string load_shader(
    const std::string &name,
    const opengl_core::gl_version &version);

  static void exe_path(const std::string &pwd);

  static const std::string &exe_path();

private:
  static std::string exe_path_;
};

#endif
