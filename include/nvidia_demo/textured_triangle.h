#ifndef TEXTURED_TRIANGLE_H_INCLUDED
#define TEXTURED_TRIANGLE_H_INCLUDED

#include "nvidia_demo/irenderable.h"

#include <array>
#include <memory>

class TexturedTriangle : public IRenderable
{
public:
  typedef Supported::Vec3Tex2 BaseAttributes_t;

public:
  explicit TexturedTriangle(const opengl_core::gl_version &version);

  TexturedTriangle(
    const opengl_core::gl_version &version,
    std::array<BaseAttributes_t, 3> &vertices);

  virtual ~TexturedTriangle();

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  bool load(const std::array<BaseAttributes_t, 3> &attributes);

  bool load(
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures);

  bool load(
    const std::array<BaseAttributes_t, 3> &attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures);

  const std::array<BaseAttributes_t, 3> &vertices() const;

  bool is_valid() const;

private:
  std::array<BaseAttributes_t, 3> vertices_;
  std::unique_ptr<Textures> textures_;
};

#endif
