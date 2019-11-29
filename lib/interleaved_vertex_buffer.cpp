#include "nvidia_demo/interleaved_vertex_buffer.h"

InterleavedVertexBuffer::InterleavedVertexBuffer(
  const std::vector<glm::vec2> &attributes, const Usage &usage) :
  usage_(usage)
{
  if (attributes.empty()) {
    throw std::runtime_error("Cannot create vertex buffer from no data.");
  }

  glGenBuffers(1, &id_);
  GL_CALL(glGenBuffers)

  glBindBuffer(GL_ARRAY_BUFFER, id_);
  GL_CALL(glBindBuffer)

  std::size_t size = sizeof(attributes[0]) * attributes.size();

  switch (usage) {
    case Usage::STREAM_DRAW: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STREAM_DRAW);
    }
      break;
    case Usage::STREAM_READ: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STREAM_READ);
    }
      break;
    case Usage::STREAM_COPY: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STREAM_COPY);
    }
      break;
    case Usage::STATIC_DRAW: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STATIC_DRAW);
    }
      break;
    case Usage::STATIC_READ: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STATIC_READ);
    }
      break;
    case Usage::STATIC_COPY: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_STATIC_COPY);
    }
      break;
    case Usage::DYNAMIC_DRAW: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_DYNAMIC_DRAW);
    }
      break;
    case Usage::DYNAMIC_READ: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_DYNAMIC_READ);
    }
      break;
    case Usage::DYNAMIC_COPY: {
      glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), GL_DYNAMIC_COPY);
    }
      break;
  }
  GL_CALL(glBufferData)
}

InterleavedVertexBuffer::~InterleavedVertexBuffer()
{
  glDeleteBuffers(1, &id_);
  GL_CALL(glDeleteBuffers)
}

const InterleavedVertexBuffer::Usage &InterleavedVertexBuffer::usage() const
{
  return usage_;
}

void InterleavedVertexBuffer::use() const
{
  glBindBuffer(GL_ARRAY_BUFFER, id_);
  GL_CALL(glBindBuffer)
}
