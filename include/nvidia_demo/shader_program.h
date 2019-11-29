#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/shader.h"

#include <atomic>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>

class ShaderProgram
{
public:
  ShaderProgram();

  ~ShaderProgram();

  ShaderProgram(const ShaderProgram &) = delete;

  ShaderProgram &operator=(const ShaderProgram &) = delete;

  ShaderProgram(const ShaderProgram &&) = delete;

  ShaderProgram &operator=(const ShaderProgram &&) = delete;

  void add_shader(const std::unique_ptr<Shader> &shader);

  void link() const;

  void use() const;

  const GLuint &id() const;

private:
  static bool linker_errors(GLuint program_id, std::string &out_errors);

private:
  GLuint id_;
  mutable std::atomic_bool linked_;
};

#endif
