#ifndef TRIANGLE_STREAM_H_INCLUDED
#define TRIANGLE_STREAM_H_INCLUDED

#include "nvidia_demo/triangle.h"
#include "nvidia_demo/textured_triangle.h"
#include "nvidia_demo/interleaved_vertex_buffer.h"

#include <memory>

class TriangleStream
{
public:
  static std::unique_ptr<InterleavedVertexBuffer> upload(
    const std::vector<std::unique_ptr<Triangle>> &triangles,
    const InterleavedVertexBuffer::Usage &usage);

  static std::unique_ptr<InterleavedVertexBuffer> upload(
    const std::vector<std::unique_ptr<TexturedTriangle>> &triangles,
    const InterleavedVertexBuffer::Usage &usage);
};

#endif
