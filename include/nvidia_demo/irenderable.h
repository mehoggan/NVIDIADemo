#ifndef IRENDERABLE_H_INCLUDED
#define IRENDERABLE_H_INCLUDED

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/idrawable.h"
#include "nvidia_demo/itransformable.h"
#include "nvidia_demo/interleaved_vertex_buffer.h"
#include "nvidia_demo/shader_program.h"
#include "nvidia_demo/textures.h"

#include <memory>

class IRenderable : public IDrawable, public ITransformable
{
public:
  explicit IRenderable(const opengl_core::gl_version &version);

  virtual ~IRenderable();

  IRenderable(const IRenderable&) = delete;

  IRenderable &operator=(const IRenderable&) = delete;

  IRenderable(IRenderable&&) = delete;

  IRenderable &operator=(IRenderable&&) = delete;

  virtual bool load() = 0;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes) = 0;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename) = 0;

  virtual bool load(
    std::unique_ptr<InterleavedVertexBuffer> &&attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures) = 0;

  virtual bool draw() = 0;

  virtual bool destroy() = 0;

  virtual const glm::mat4 &model() const = 0;

  virtual void model(const glm::mat4 &model) = 0;

protected:
  opengl_core::gl_version version_;
  std::unique_ptr<ShaderProgram> program_;
  std::unique_ptr<InterleavedVertexBuffer> attributes_;
  std::unique_ptr<Textures> textures_;
};

#endif
