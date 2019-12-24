#ifndef TEXTURED_SQUARE_H_INCLUDED
#define TEXTURED_SQUARE_H_INCLUDED

#include "nvidia_demo/irenderable.h"
#include "nvidia_demo/textured_triangle.h"

#include <array>

class TexturedSquare : public IRenderable
{
public:
  typedef Supported::Vec3Tex2 BaseAttributes_t;

public:
  explicit TexturedSquare(const opengl_core::gl_version &version);

  virtual ~TexturedSquare();

  TexturedSquare(const TexturedSquare &) = delete;

  TexturedSquare &operator=(const TexturedSquare &) = delete;

  TexturedSquare(TexturedSquare &&) = delete;

  TexturedSquare &operator=(TexturedSquare &&) = delete;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  bool load(
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures);

  const std::array<std::unique_ptr<TexturedTriangle>, 2> &triangles() const;

  bool is_valid() const;

private:
  TexturedSquare(
    const opengl_core::gl_version &version,
    const std::array<std::unique_ptr<TexturedTriangle>, 2> &clone);

private:
  std::array<std::unique_ptr<TexturedTriangle>, 2> triangles_;
  std::unique_ptr<Textures> textures_;
};

#endif
