#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "nvidia_demo/irenderable.h"

#include <array>

class Triangle : public IRenderable
{
public:
  typedef Supported::Vec3Col3 BaseAttributes_t;

public:
  explicit Triangle(const opengl_core::gl_version &version);

  Triangle(
    const opengl_core::gl_version &version,
    const std::array<BaseAttributes_t, 3> &vertices);

  virtual ~Triangle();

  Triangle(const Triangle &) = delete;

  Triangle &operator=(const Triangle &) = delete;

  Triangle(Triangle &&) = delete;

  Triangle &operator=(Triangle &&) = delete;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  bool load(const std::array<BaseAttributes_t, 3> &attributes);

  bool load(
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename);

  bool load(
    const std::array<BaseAttributes_t, 3> &attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename);

  bool load(
    const std::array<BaseAttributes_t, 3> &attributes,
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename,
    std::unique_ptr<Textures> &&textures);

  const std::array<BaseAttributes_t, 3> &vertices() const;

  bool is_valid() const;

private:
  std::array<BaseAttributes_t, 3> vertices_;
};

#endif
