#include "nvidia_demo/triangle_stream.h"

std::unique_ptr<InterleavedVertexBuffer> TriangleStream::upload(
  const std::vector<std::unique_ptr<Triangle>> &triangles,
  const InterleavedVertexBuffer::Usage &usage)
{
  std::vector<Triangle::BaseAttributes_t> input;
  for (const std::unique_ptr<Triangle> &triangle : triangles) {
    const std::array<Triangle::BaseAttributes_t, 3> tri =
      triangle->vertices();
    std::copy(tri.begin(), tri.end(), std::back_inserter(input));
  }
  return std::make_unique<InterleavedVertexBuffer>(input, usage);
}

std::unique_ptr<InterleavedVertexBuffer> TriangleStream::upload(
  const std::vector<std::unique_ptr<TexturedTriangle>> &triangles,
  const InterleavedVertexBuffer::Usage &usage)
{
  std::vector<TexturedTriangle::BaseAttributes_t> input;
  for (const std::unique_ptr<TexturedTriangle> &triangle : triangles) {
    const std::array<TexturedTriangle::BaseAttributes_t, 3> tri =
      triangle->vertices();
    std::copy(tri.begin(), tri.end(), std::back_inserter(input));
  }
  return std::make_unique<InterleavedVertexBuffer>(input, usage);
}
