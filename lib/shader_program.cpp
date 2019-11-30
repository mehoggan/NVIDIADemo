#include "nvidia_demo/shader_program.h"

#include <glm/gtc/type_ptr.hpp>

#include <algorithm>
#include <iostream>

ShaderProgram::ShaderProgram() :
  linked_(false)
{
  id_ = glCreateProgram();
  GL_CALL(glCreateProgram);
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(id_);
  GL_CALL(glDeleteProgram)
}

const GLuint &ShaderProgram::id() const
{
  return id_;
}

void ShaderProgram::add_shader(const std::unique_ptr<Shader> &shader)
{
  glAttachShader(id_, shader->id());
  GL_CALL(glAttachShader)
}

void ShaderProgram::link() const
{
  if (not linked_.load()) {
    glLinkProgram(id_);
    GL_CALL(glLinkProgram);

    std::string errors;
    if (linker_errors(id_, errors) == GL_TRUE) {
      throw std::runtime_error(
        std::string("Failed to link shader program with error:\n") + errors);
    }

    linked_.store(true);
  }
}

void ShaderProgram::use() const
{
  glUseProgram(id_);
  GL_CALL(glUseProgram);
}

void ShaderProgram::activate_attribute(
  const std::string &attr,
  std::size_t attr_index,
  const InterleavedVertexBuffer &attributes) const
{
  InterleavedVertexBuffer::AttributeProperties properties;
  attributes.properties(attr_index, properties);
  GLint size = properties.size;
  GLsizei stride = properties.stride;
  void *offset = properties.offset;

  GLint pos = glGetAttribLocation(id_, attr.c_str());
  GL_CALL(glGetAttribLocation)

  glEnableVertexAttribArray(pos);
  GL_CALL(glEnableVertexAttribArray)

  glVertexAttribPointer(pos, size, GL_FLOAT, GL_FALSE, stride, offset);
  GL_CALL(glVertexAttribPointer)
}

GLint ShaderProgram::get_uniform_id(const std::string &uniform)
{
  GLint id = glGetUniformLocation(id_, uniform.c_str());
  GL_CALL(glGetUniformLocation)
  return id;
}

void ShaderProgram::set_uniform1f(GLint uniform_id, GLfloat v0)
{
  glUniform1f(uniform_id, v0);
  GL_CALL(glUnifrom1f)
}

void ShaderProgram::set_uniform2f(
  GLint uniform_id,
  GLfloat v0,
  GLfloat v1)
{
  glUniform2f(uniform_id, v0, v1);
  GL_CALL(glUniform2f)
}

void ShaderProgram::set_uniform3f(
  GLint uniform_id,
  GLfloat v0,
  GLfloat v1,
  GLfloat v2)
{
  glUniform3f(uniform_id, v0, v1, v2);
  GL_CALL(glUniform3f)
}
 
void ShaderProgram::set_uniform4f(
  GLint uniform_id,
  GLfloat v0,
  GLfloat v1,
  GLfloat v2,
  GLfloat v3)
{
  glUniform4f(uniform_id, v0, v1, v2, v3);
  GL_CALL(glUniform4f)
}
 
void ShaderProgram::set_uniform1i(
  GLint uniform_id,
  GLint v0)
{
  glUniform1i(uniform_id, v0);
  GL_CALL(glUniform1i)
}
 
void ShaderProgram::set_uniform2i(
  GLint uniform_id,
  GLint v0,
  GLint v1)
{
  glUniform2i(uniform_id, v0, v1);
  GL_CALL(glUniform2i)
}
 
void ShaderProgram::set_uniform3i(
  GLint uniform_id,
  GLint v0,
  GLint v1,
  GLint v2)
{
  glUniform3i(uniform_id, v0, v1, v2);
  GL_CALL(glUniform3i)
}
 
void ShaderProgram::set_uniform4i(
  GLint uniform_id,
  GLint v0,
  GLint v1,
  GLint v2,
  GLint v3)
{
  glUniform4i(uniform_id, v0, v1, v2, v3);
  GL_CALL(glUniform4i)
}
 
void ShaderProgram::set_uniform1ui(
  GLint uniform_id,
  GLuint v0)
{
  glUniform1ui(uniform_id, v0);
  GL_CALL(glUniform1ui)
}
 
void ShaderProgram::set_uniform2ui(
  GLint uniform_id,
  GLuint v0,
  GLuint v1)
{
  glUniform2ui(uniform_id, v0, v1);
  GL_CALL(glUniform2ui)
}
 
void ShaderProgram::set_uniform3ui(
  GLint uniform_id,
  GLuint v0,
  GLuint v1,
  GLuint v2)
{
  glUniform3ui(uniform_id, v0, v1, v2);
  GL_CALL(glUniform3ui)
}
 
void ShaderProgram::set_uniform4ui(
  GLint uniform_id,
  GLuint v0,
  GLuint v1,
  GLuint v2,
  GLuint v3)
{
  glUniform4ui(uniform_id, v0, v1, v2, v3);
  GL_CALL(glUniform4ui)
}
 
void ShaderProgram::set_uniform1fv(
  GLint uniform_id,
  const std::array<GLfloat, 1> &a)
{
  glUniform1fv(uniform_id, 1, a.data());
  GL_CALL(glUniform1fv)
}

void ShaderProgram::set_uniform2fv(
  GLint uniform_id,
  const std::array<GLfloat, 2> &a)
{
  glUniform2fv(uniform_id, 2, a.data());
  GL_CALL(glUniform2fv)
}

void ShaderProgram::set_uniform3fv(
  GLint uniform_id,
  const std::array<GLfloat, 3> &a)
{
  glUniform3fv(uniform_id, 3, a.data());
  GL_CALL(glUniform3fv)
}

void ShaderProgram::set_uniform4fv(
  GLint uniform_id,
  const std::array<GLfloat, 4> &a)
{
  glUniform4fv(uniform_id, 4, a.data());
  GL_CALL(glUniform4fv)
}

void ShaderProgram::set_uniform1iv(
  GLint uniform_id,
  const std::array<GLint, 1> &a)
{
  glUniform1iv(uniform_id, 1, a.data());
  GL_CALL(glUniform1iv)
}

void ShaderProgram::set_uniform2iv(
  GLint uniform_id,
  const std::array<GLint, 2> &a)
{
  glUniform2iv(uniform_id, 2, a.data());
  GL_CALL(glUniform2iv)
}

void ShaderProgram::set_uniform3iv(
  GLint uniform_id,
  const std::array<GLint, 3> &a)
{
  glUniform3iv(uniform_id, 3, a.data());
  GL_CALL(glUniform3iv)
}

void ShaderProgram::set_uniform4iv(
  GLint uniform_id,
  const std::array<GLint, 4> &a)
{
  glUniform4iv(uniform_id, 4, a.data());
  GL_CALL(glUniform4iv)
}

void ShaderProgram::set_uniform1uiv(
  GLint uniform_id,
  const std::array<GLuint, 1> &a)
{
  glUniform1uiv(uniform_id, 1, a.data());
  GL_CALL(glUniform1iv)
}

void ShaderProgram::set_uniform2uiv(
  GLint uniform_id,
  const std::array<GLuint, 2> &a)
{
  glUniform2uiv(uniform_id, 2, a.data());
  GL_CALL(glUniform2iv)
}

void ShaderProgram::set_uniform3uiv(
  GLint uniform_id,
  const std::array<GLuint, 3> &a)
{
  glUniform3uiv(uniform_id, 3, a.data());
  GL_CALL(glUniform3iv)
}

void ShaderProgram::set_uniform4uiv(
  GLint uniform_id,
  const std::array<GLuint, 4> &a)
{
  glUniform4uiv(uniform_id, 4, a.data());
  GL_CALL(glUniform4iv)
}
 
void ShaderProgram::set_uniform_matrix2fv(
  GLint uniform_id,
  const glm::mat2 &m,
  bool trans)
{
  glUniformMatrix2fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix2fv)
}

void ShaderProgram::set_uniform_matrix3fv(
  GLint uniform_id,
  const glm::mat3 &m,
  bool trans)
{
  glUniformMatrix3fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix3fv)
}
 
void ShaderProgram::set_uniform_matrix4fv(
  GLint uniform_id,
  const glm::mat4 &m,
  bool trans)
{
  glUniformMatrix4fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix4fv)
}

void ShaderProgram::set_uniform_matrix_2x3fv(
  GLint uniform_id,
  const glm::mat2x3 &m,
  bool trans)
{
  glUniformMatrix2x3fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix2x3fv)
}

void ShaderProgram::set_uniform_matrix_3x2fv(
  GLint uniform_id,
  const glm::mat3x2 &m,
  bool trans)
{
  glUniformMatrix3x2fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix3x2fv)
}

void ShaderProgram::set_uniform_matrix_2x4fv(
  GLint uniform_id,
  const glm::mat2x4 &m,
  bool trans)
{
  glUniformMatrix2x4fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix2x4fv)
}

void ShaderProgram::set_uniform_matrix_4x2fv(
  GLint uniform_id,
  const glm::mat4x2 &m,
  bool trans)
{
  glUniformMatrix4x2fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix4x2fv)
}

void ShaderProgram::set_uniform_matrix_3x4fv(
  GLint uniform_id,
  const glm::mat3x4 &m,
  bool trans)
{
  glUniformMatrix3x4fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix3x4fv)
}

void ShaderProgram::set_uniform_matrix_4x3fv(
  GLint uniform_id,
  const glm::mat4x3 &m,
  bool trans)
{
  glUniformMatrix4x3fv(uniform_id, 1, trans, glm::value_ptr(m));
  GL_CALL(glUniformMatrix4x3fv)
}

bool ShaderProgram::linker_errors(GLuint program_id, std::string &out_errors)
{
  bool errors = false;

  GLint is_linked = 0;

  glGetProgramiv(program_id, GL_LINK_STATUS, &is_linked);
  GL_CALL(glGetProgramiv)

  if(is_linked == GL_FALSE) {
    GLint max_length = 0;

    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &max_length);
    GL_CALL(glGetShaderiv)

    std::vector<char> error_log(max_length);
    glGetProgramInfoLog(program_id, max_length, &max_length, &error_log[0]);
    GL_CALL(glGetProgramInfoLog)

    std::stringstream out;
    std::copy(error_log.begin(), error_log.end(),
      std::ostream_iterator<char>(out, ""));
    out_errors = out.str();
    errors = true;
  }

  return errors;
}
