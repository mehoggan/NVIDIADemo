#include "nvidia_demo/shader_program.h"

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
