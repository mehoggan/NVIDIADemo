#include "nvidia_demo/resource_loader.h"

#include <iostream>
#include <fstream>
#include <streambuf>

std::string ResourceLoader::exe_path_;

std::string ResourceLoader::load_shader(const std::string &name)
{
  std::string absolute_path = exe_path_ + "/" + std::string("shaders/") +
    name; 
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
