#ifndef INTERLEAVED_VERTEX_BUFFER_H_INCLUDED
#define INTERLEAVED_VERTEX_BUFFER_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <stddef.h>

namespace Supported
{
  typedef glm::vec2 Vec2;
  typedef glm::vec3 Vec3;

  struct Vec2Col3
  {
    Vec2 pos_;
    Vec3 col_;
  };

  struct Vec3Col3
  {
    Vec3 pos_;
    Vec3 col_;
  };

  struct Vec2Col3Tex2
  {
    Vec2 pos_;
    Vec3 col_;
    Vec2 tex_;
  };

  struct Vec3Col3Tex2
  {
    Vec3 pos_;
    Vec3 col_;
    Vec2 tex_;
  };

  typedef std::uint8_t uByte;

  typedef std::uint16_t uShort;

  typedef std::int32_t Integer;
}

class InterleavedVertexBuffer
{
public:
  enum class Usage
  {
    STREAM_DRAW,
    STREAM_READ,
    STREAM_COPY,
    STATIC_DRAW,
    STATIC_READ,
    STATIC_COPY,
    DYNAMIC_DRAW,
    DYNAMIC_READ,
    DYNAMIC_COPY
  };

  enum class IndexType
  {
    UNSIGNED_BYTE,
    UNSIGNED_SHORT,
    UNSIGNED_INT
  };

  struct AttributeProperties
  {
    GLint size;
    GLsizei stride;
    void *offset;
  };

public:
  InterleavedVertexBuffer(
    const std::vector<Supported::Vec2> &attributes,
    const Usage &usage);

  InterleavedVertexBuffer(
    const std::vector<Supported::Vec3Col3> &attributes,
    const Usage &usage);

  InterleavedVertexBuffer(
    const std::vector<Supported::Vec2Col3> &attributes,
    const std::vector<Supported::Integer> &indices,
    const Usage &usage);

  InterleavedVertexBuffer(
    const std::vector<Supported::Vec2Col3Tex2> &attributes,
    const std::vector<Supported::Integer> &indices,
    const Usage &usage);

  InterleavedVertexBuffer(
    const std::vector<Supported::Vec3Col3Tex2> &attributes,
    const Usage &usage);

  InterleavedVertexBuffer(
    const std::vector<Supported::Vec3Col3Tex2> &attributes,
    const std::vector<Supported::Integer> &indices,
    const Usage &usage);

  ~InterleavedVertexBuffer();

  InterleavedVertexBuffer(const InterleavedVertexBuffer &) = delete;

  InterleavedVertexBuffer &operator=(const InterleavedVertexBuffer &)
    = delete;

  InterleavedVertexBuffer(InterleavedVertexBuffer &&) = delete;

  InterleavedVertexBuffer &operator=(InterleavedVertexBuffer &&) = delete;

  const Usage &usage() const;

  void use() const;

  void properties(
    std::size_t attr_index,
    AttributeProperties &out_props) const;

  bool is_indexed() const;

private:
  GLuint id_;
  GLuint index_id_;
  Usage usage_;
  std::vector<GLint> sizes_;
  std::vector<GLsizei> strides_;
  std::vector<void *> offsets_;
};

#endif
