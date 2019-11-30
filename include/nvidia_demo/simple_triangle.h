#ifndef SIMPLE_TRIANGLE_H_INCLUDED
#define SIMPLE_TRIANGLE_H_INCLUDED

#include "nvidia_demo/idrawable.h"

#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/shader.h"
#include "nvidia_demo/shader_program.h"

#include <memory>

class SimpleTriangle : public IDrawable
{
public:
  explicit SimpleTriangle(const opengl_core::gl_version &version);

  virtual ~SimpleTriangle();

  SimpleTriangle(const SimpleTriangle &) = delete;

  SimpleTriangle &operator=(const SimpleTriangle &) = delete;

  SimpleTriangle(SimpleTriangle &&) = delete;

  SimpleTriangle &operator=(SimpleTriangle &&) = delete;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

private:
  opengl_core::gl_version version_;
  std::unique_ptr<InterleavedVertexBuffer> attributes_;
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  std::unique_ptr<ShaderProgram> shader_program_;
};

#endif
