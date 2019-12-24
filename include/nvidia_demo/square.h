#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "nvidia_demo/irenderable.h"
#include "nvidia_demo/triangle.h"

#include <array>

class Square : public IRenderable
{
public:
  typedef Supported::Vec3Col3 BaseAttributes_t;

public:
  explicit Square(const opengl_core::gl_version &version);

  virtual ~Square();

  Square(const Square &) = delete;

  Square &operator=(const Square &) = delete;

  Square(Square &&) = delete;

  Square &operator=(Square &&) = delete;

  virtual bool load() override;

  virtual bool draw() override;

  virtual bool destroy() override;

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  bool load(
    const std::string &vertex_shader_filename,
    const std::string &fragment_shader_filename);

  const std::array<std::unique_ptr<Triangle>, 2> &triangles() const;

  bool is_valid() const;

private:
  Square(
    const opengl_core::gl_version &version,
    const std::array<std::unique_ptr<Triangle>, 2> &clone);

private:
  std::array<std::unique_ptr<Triangle>, 2> triangles_;
};

#endif
