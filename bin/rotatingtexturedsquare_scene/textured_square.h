#ifndef RAINDBOW_SQUARE_H_INCLUDED
#define RAINDBOW_SQUARE_H_INCLUDED

#include "nvidia_demo/idrawable.h"

#include "nvidia_demo/camera.h"
#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/itransformable.h"
#include "nvidia_demo/shader.h"
#include "nvidia_demo/shader_program.h"
#include "nvidia_demo/textures.h"

#include <chrono>
#include <memory>

class TexturedSquare : public IDrawable, public ITransformable
{
public:
  explicit TexturedSquare(const opengl_core::gl_version &version);

  virtual ~TexturedSquare();

  TexturedSquare(const TexturedSquare &) = delete;

  TexturedSquare &operator=(const TexturedSquare &) = delete;

  TexturedSquare(TexturedSquare &&) = delete;

  TexturedSquare &operator=(TexturedSquare &&) = delete;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

private:
  void compute_transform();

private:
  opengl_core::gl_version version_;
  std::unique_ptr<InterleavedVertexBuffer> attributes_;
  std::unique_ptr<Shader> vertex_shader_;
  std::unique_ptr<Shader> fragment_shader_;
  std::unique_ptr<ShaderProgram> shader_program_;
  std::unique_ptr<Textures> textures_;
  Camera camera_;
  std::chrono::high_resolution_clock::time_point rotation_;
};

#endif
