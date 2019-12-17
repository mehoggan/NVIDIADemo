#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/shader.h"

#include <glm/mat2x2.hpp>
#include <glm/mat2x3.hpp>
#include <glm/mat2x4.hpp>
#include <glm/mat3x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat3x4.hpp>
#include <glm/mat4x2.hpp>
#include <glm/mat4x3.hpp>
#include <glm/mat4x4.hpp>

#include <atomic>
#include <iterator>
#include <memory>
#include <sstream>

class ShaderProgram
{
public:
  enum class UniformType
  {
    FLOAT_3
  };

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

  GLint get_uniform_id(const std::string &uniform);

  void set_uniform1f(
    GLint uniform_id,
    GLfloat v0);
 
  void set_uniform2f(
    GLint uniform_id,
    GLfloat v0,
    GLfloat v1);
 
  void set_uniform3f(GLint uniform_id, GLfloat v0, GLfloat v1, GLfloat v2);
   
  void set_uniform4f(
    GLint uniform_id,
    GLfloat v0,
    GLfloat v1,
    GLfloat v2,
    GLfloat v3);
   
  void set_uniform1i(
    GLint uniform_id,
    GLint v0);
   
  void set_uniform2i(
    GLint uniform_id,
    GLint v0,
    GLint v1);
   
  void set_uniform3i(
    GLint uniform_id,
    GLint v0,
    GLint v1,
    GLint v2);
   
  void set_uniform4i(
    GLint uniform_id,
    GLint v0,
    GLint v1,
    GLint v2,
    GLint v3);
   
  void set_uniform1ui(
    GLint uniform_id,
    GLuint v0);
   
  void set_uniform2ui(
    GLint uniform_id,
    GLuint v0,
    GLuint v1);
   
  void set_uniform3ui(
    GLint uniform_id,
    GLuint v0,
    GLuint v1,
    GLuint v2);
   
  void set_uniform4ui(
    GLint uniform_id,
    GLuint v0,
    GLuint v1,
    GLuint v2,
    GLuint v3);
   
  void set_uniform1fv(
    GLint uniform_id,
    const std::array<GLfloat, 1> &a);

  void set_uniform2fv(
    GLint uniform_id,
    const std::array<GLfloat, 2> &a);

  void set_uniform3fv(
    GLint uniform_id,
    const std::array<GLfloat, 3> &a);

  void set_uniform4fv(
    GLint uniform_id,
    const std::array<GLfloat, 4> &a);

  void set_uniform1iv(
    GLint uniform_id,
    const std::array<GLint, 1> &a);

  void set_uniform2iv(
    GLint uniform_id,
    const std::array<GLint, 2> &a);

  void set_uniform3iv(
    GLint uniform_id,
    const std::array<GLint, 3> &a);

  void set_uniform4iv(
    GLint uniform_id,
    const std::array<GLint, 4> &a);

  void set_uniform1uiv(
    GLint uniform_id,
    const std::array<GLuint, 1> &a);

  void set_uniform2uiv(
    GLint uniform_id,
    const std::array<GLuint, 2> &a);

  void set_uniform3uiv(
    GLint uniform_id,
    const std::array<GLuint, 3> &a);

  void set_uniform4uiv(
    GLint uniform_id,
    const std::array<GLuint, 4> &a);
   
  void set_uniform_matrix2fv(
    GLint uniform_id,
    const glm::mat2 &m,
    bool trans = false);

  void set_uniform_matrix3fv(
    GLint uniform_id,
    const glm::mat3 &m,
    bool trans = false);
   
  void set_uniform_matrix4fv(
    GLint uniform_id,
    const glm::mat4 &m,
    bool trans = false);

  void set_uniform_matrix_2x3fv(
    GLint uniform_id,
    const glm::mat2x3 &m,
    bool trans = false);

  void set_uniform_matrix_3x2fv(
    GLint uniform_id,
    const glm::mat3x2 &m,
    bool trans = false);

  void set_uniform_matrix_2x4fv(
    GLint uniform_id,
    const glm::mat2x4 &m,
    bool trans = false);

  void set_uniform_matrix_4x2fv(
    GLint uniform_id,
    const glm::mat4x2 &m,
    bool trans = false);

  void set_uniform_matrix_3x4fv(
    GLint uniform_id,
    const glm::mat3x4 &m,
    bool trans = false);

  void set_uniform_matrix_4x3fv(
    GLint uniform_id,
    const glm::mat4x3 &m,
    bool trans = false);

private:
  static bool linker_errors(GLuint program_id, std::string &out_errors);

private:
  GLuint id_;
  mutable std::atomic_bool linked_;
};

#endif
