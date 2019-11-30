#ifndef FLASHING_TRIANGLE_H_INCLUDED
#define FLASHING_TRIANGLE_H_INCLUDED

#include "nvidia_demo/idrawable.h"

#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/shader.h"
#include "nvidia_demo/shader_program.h"

#include <chrono>
#include <memory>

class FlashingTriangle : public IDrawable
{
public:
  explicit FlashingTriangle(const opengl_core::gl_version &version);

  virtual ~FlashingTriangle();

  FlashingTriangle(const FlashingTriangle &) = delete;

  FlashingTriangle &operator=(const FlashingTriangle &) = delete;

  FlashingTriangle(FlashingTriangle &&) = delete;

  FlashingTriangle &operator=(FlashingTriangle &&) = delete;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

private:
  std::chrono::high_resolution_clock::time_point start_;
  opengl_core::gl_version version_;
  std::unique_ptr<InterleavedVertexBuffer> attributes_;
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  std::unique_ptr<ShaderProgram> shader_program_;
};

#endif
