#ifndef RESOURCE_LOADER_H_INCLUDED
#define RESOURCE_LOADER_H_INCLUDED

#include <string>



class ResourceLoader
{
public:
  static std::string load_shader(const std::string &name);

  static void exe_path(const std::string &pwd);

  static const std::string &exe_path();

private:
  static std::string exe_path_;
};

#endif
