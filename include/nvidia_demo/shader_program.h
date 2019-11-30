#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/shader.h"

#include <atomic>
#include <iterator>
#include <memory>
#include <sstream>

class ShaderProgram
{
public:
  ShaderProgram();

  ~ShaderProgram();

  ShaderProgram(const ShaderProgram &) = delete;

  ShaderProgram &operator=(const ShaderProgram &) = delete;

  ShaderProgram(ShaderProgram &&) = delete;

  ShaderProgram &operator=(ShaderProgram &&) = delete;

  const GLuint &id() const;

  void add_shader(const std::unique_ptr<Shader> &shader);

  void link() const;

  void use() const;

  void activate_attribute(
    const std::string &attr,
    std::size_t attr_index,
    const InterleavedVertexBuffer &attributes) const;

private:
  static bool linker_errors(GLuint program_id, std::string &out_errors);

private:
  GLuint id_;
  mutable std::atomic_bool linked_;
};

#endif
