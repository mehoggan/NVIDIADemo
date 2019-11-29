#include "nvidia_demo/shader.h"

#include <iterator>
#include <sstream>
#include <string>

Shader::Shader(const std::string &source, const Type &type) :
  source_(source),
  type_(type)
{
  switch (type) {
  case Type::VERTEX: {
    id_ = glCreateShader(GL_VERTEX_SHADER);
  }
    break;
  case Type::GEOMETRY: {
    id_ = glCreateShader(GL_GEOMETRY_SHADER);
  }
    break;
  case Type::FRAGMENT: {
    id_ = glCreateShader(GL_FRAGMENT_SHADER);
  }
    break;
  }
  GL_CALL(glCreateShader)

  const GLchar *source_ptr = source_.c_str();
  glShaderSource(id_, 1, &source_ptr, NULL);
  GL_CALL(glShaderSource)

  glCompileShader(id_);
  GL_CALL(glCompileShader)

  std::string errors;
  if(compiler_errors(id_, errors) == GL_TRUE) {
    throw std::runtime_error(
      std::string("Failed to compile ") + type_string(type_) +
      " shader with:\n" + errors + "\n\n source: \n" + source_ +
      "\n");
  }
}

Shader::~Shader()
{
  glDeleteShader(id_);
  GL_CALL(glDeleteShader)
}

const Shader::Type &Shader::type() const
{
  return type_;
}

const GLuint &Shader::id() const
{
  return id_;
}

bool Shader::compiler_errors(
  GLuint shader_id,
  std::string &out_errors)
{
  bool errors = false;

  GLint is_compiled = 0;

  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &is_compiled);
  GL_CALL(glGetShaderiv)

  if(is_compiled == GL_FALSE) {
    GLint max_length = 0;

    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &max_length);
    GL_CALL(glGetShaderiv)

    std::vector<char> error_log(max_length);
    glGetShaderInfoLog(shader_id, max_length, &max_length, &error_log[0]);
    GL_CALL(glGetShaderInfoLog)

    std::stringstream out;
    std::copy(error_log.begin(), error_log.end(),
      std::ostream_iterator<char>(out, ""));
    out_errors = out.str();
    errors = true;
  }

  return errors;
}

std::string Shader::type_string(const Type &type)
{
  switch (type) {
  case Type::VERTEX: {
    return "vertex";
  }
  case Type::GEOMETRY: {
    return "geometry";
  }
  case Type::FRAGMENT: {
    return "fragment";
  }
  }

  throw std::runtime_error("Invalid type enum for shader.");
}
