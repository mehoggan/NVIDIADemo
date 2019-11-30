#include "nvidia_demo/interleaved_vertex_buffer.h"

namespace detail
{
  template <class Attribute>
  void load(const std::vector<Attribute> &attributes,
    const InterleavedVertexBuffer::Usage &usage)
  {
    std::size_t size = sizeof(attributes[0]) * attributes.size();

    GLenum glusage;

    switch (usage) {
      case InterleavedVertexBuffer::Usage::STREAM_DRAW: {
        glusage = GL_STREAM_DRAW;
      }
        break;
      case InterleavedVertexBuffer::Usage::STREAM_READ: {
        glusage = GL_STREAM_READ;
      }
        break;
      case InterleavedVertexBuffer::Usage::STREAM_COPY: {
        glusage = GL_STREAM_COPY;
      }
        break;
      case InterleavedVertexBuffer::Usage::STATIC_DRAW: {
        glusage = GL_STATIC_DRAW;
      }
        break;
      case InterleavedVertexBuffer::Usage::STATIC_READ: {
        glusage = GL_STATIC_READ;
      }
        break;
      case InterleavedVertexBuffer::Usage::STATIC_COPY: {
        glusage = GL_STATIC_COPY;
      }
        break;
      case InterleavedVertexBuffer::Usage::DYNAMIC_DRAW: {
        glusage = GL_DYNAMIC_DRAW;
      }
        break;
      case InterleavedVertexBuffer::Usage::DYNAMIC_READ: {
        glusage = GL_DYNAMIC_READ;
      }
        break;
      case InterleavedVertexBuffer::Usage::DYNAMIC_COPY: {
        glusage = GL_DYNAMIC_COPY;
      }
        break;
    }
    glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), glusage);
    GL_CALL(glBufferData)
  }
}

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

  detail::load<glm::vec2>(attributes, usage);

  sizes_.push_back(2);
  strides_.push_back(0);
  offsets_.push_back((void *)0);
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

void InterleavedVertexBuffer::properties(
  std::size_t attr_index,
  AttributeProperties &out_props) const
{
  out_props = {
    sizes_[attr_index],
    strides_[attr_index],
    offsets_[attr_index] };
}
