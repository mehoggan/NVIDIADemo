#include "nvidia_demo/interleaved_vertex_buffer.h"

namespace detail
{
  GLenum get_gl_usage(const InterleavedVertexBuffer::Usage &usage)
  {
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

    return glusage;
  }

  template <class Attribute>
  void load(const std::vector<Attribute> &attributes,
    const InterleavedVertexBuffer::Usage &usage)
  {
    std::size_t size = sizeof(attributes[0]) * attributes.size();
    GLenum glusage = get_gl_usage(usage);
    glBufferData(GL_ARRAY_BUFFER, size, attributes.data(), glusage);
    GL_CALL(glBufferData)
  }

  template <class Index>
  void load_indices(
    const std::vector<Index> &indices,
    const InterleavedVertexBuffer::Usage &usage)
  {
    std::size_t size = sizeof(indices[0]) * indices.size();
    GLenum glusage = get_gl_usage(usage);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), glusage);
    GL_CALL(glBufferData);
  }
}

InterleavedVertexBuffer::InterleavedVertexBuffer(
  const std::vector<glm::vec2> &attributes, const Usage &usage) :
  index_id_(-1),
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

InterleavedVertexBuffer::InterleavedVertexBuffer(
  const std::vector<Supported::Vec2Col3> &attributes,
  const std::vector<Supported::Integer> &indices,
  const Usage &usage)
{
  if (attributes.empty()) {
    throw std::runtime_error("Cannot create vertex buffer from no data.");
  }

  glGenBuffers(1, &id_);
  GL_CALL(glGenBuffers)

  glBindBuffer(GL_ARRAY_BUFFER, id_);
  GL_CALL(glBindBuffer)

  detail::load<Supported::Vec2Col3>(attributes, usage);
  sizes_.push_back(2);
  sizes_.push_back(3);
  strides_.push_back(5 * sizeof(GLfloat));
  strides_.push_back(5 * sizeof(GLfloat));
  offsets_.push_back((void *)0);
  offsets_.push_back((void *)(2 * sizeof(GLfloat)));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id_);
  GL_CALL(glBindBuffer)

  detail::load_indices<Supported::Integer>(indices, usage);
}

InterleavedVertexBuffer::InterleavedVertexBuffer(
  const std::vector<Supported::Vec2Col3Tex2> &attributes,
  const std::vector<Supported::Integer> &indices,
  const Usage &usage)
{
  if (attributes.empty()) {
    throw std::runtime_error("Cannot create vertex buffer from no data.");
  }

  glGenBuffers(1, &id_);
  GL_CALL(glGenBuffers)

  glBindBuffer(GL_ARRAY_BUFFER, id_);
  GL_CALL(glBindBuffer)

  detail::load<Supported::Vec2Col3Tex2>(attributes, usage);
  sizes_.push_back(2);
  sizes_.push_back(3);
  sizes_.push_back(2);
  strides_.push_back(7 * sizeof(GLfloat));
  strides_.push_back(7 * sizeof(GLfloat));
  strides_.push_back(7 * sizeof(GLfloat));
  offsets_.push_back((void *)0);
  offsets_.push_back((void *)(2 * sizeof(GLfloat)));
  offsets_.push_back((void *)(5 * sizeof(GLfloat)));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id_);
  GL_CALL(glBindBuffer)

  detail::load_indices<Supported::Integer>(indices, usage);
}

InterleavedVertexBuffer::~InterleavedVertexBuffer()
{
  if (is_indexed()) {
    glDeleteBuffers(1, &index_id_);
    GL_CALL(glDeleteBuffers)
  }

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

  if (is_indexed()) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id_);
    GL_CALL(glBindBuffer)
  }
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


bool InterleavedVertexBuffer::is_indexed() const
{
  return index_id_ != static_cast<GLuint>(-1);
}
