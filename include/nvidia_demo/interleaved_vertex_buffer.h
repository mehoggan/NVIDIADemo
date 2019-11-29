#ifndef INTERLEAVED_VERTEX_BUFFER_H_INCLUDED
#define INTERLEAVED_VERTEX_BUFFER_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

#include <glm/vec2.hpp>

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

public:
  InterleavedVertexBuffer(const std::vector<glm::vec2> &attributes,
      const Usage &usage);

  ~InterleavedVertexBuffer();

  InterleavedVertexBuffer(const InterleavedVertexBuffer &) = delete;

  InterleavedVertexBuffer &operator=(const InterleavedVertexBuffer &)
    = delete;

  InterleavedVertexBuffer(const InterleavedVertexBuffer &&) = delete;

  InterleavedVertexBuffer &operator=(const InterleavedVertexBuffer &&)
    = delete;

  const Usage &usage() const;

  void use() const;

private:
  GLuint id_;
  Usage usage_;
};

#endif
