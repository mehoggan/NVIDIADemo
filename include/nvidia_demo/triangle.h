#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "nvidia_demo/irenderable.h"

class Triangle : public IRenderable
{
public:
  explicit Triangle(const opengl_core::gl_version &version);

  virtual ~Triangle();

  virtual bool load() override;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes) override;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename) override;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures) override;

  virtual bool draw() override;

  virtual bool destroy() override;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;
};

#endif
