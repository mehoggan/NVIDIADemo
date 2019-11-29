#include "nvidia_demo/resource_loader.h"

#include "nvidia_demo/gl_functions.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <utility>
#include <unordered_map>

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

void ResourceLoader::exe_path(const std::string &pwd)
{
  exe_path_ = pwd;
}

const std::string &ResourceLoader::exe_path()
{
  return exe_path_;
}
