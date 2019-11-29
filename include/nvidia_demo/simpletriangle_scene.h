#ifndef SQUARE_SCENE_H_INCLUDED
#define SQUARE_SCENE_H_INCLUDED

#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/iscene.h"
#include "nvidia_demo/shader.h"
#include "nvidia_demo/shader_program.h"

#include <memory>

class SimpleTriangleScene : public IScene
{
public:
  SimpleTriangleScene(const opengl_core::gl_version& version);

  virtual ~SimpleTriangleScene();

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<InterleavedVertexBuffer> attributes_;
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  std::unique_ptr<ShaderProgram> shader_program_;
};

#endif
