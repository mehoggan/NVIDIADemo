#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

#include <string>

class Shader
{
public:
  enum class Type
  {
    VERTEX,
    GEOMETRY,
    FRAGMENT
  };

public:
  Shader(const std::string &source, const Type &type);

  ~Shader();

  Shader(const Shader &) = delete;

  Shader &operator=(const Shader &) = delete;

  Shader(const Shader &&) = delete;

  Shader &operator=(const Shader &&) = delete;

  const Type &type() const;

  const GLuint &id() const;

private:
  static bool compiler_errors(
    GLuint shader_id,
    std::string &out_errors);

  static std::string type_string(const Type &type);

private:
  std::string source_;
  Type type_;
  GLuint id_;
};

#endif
