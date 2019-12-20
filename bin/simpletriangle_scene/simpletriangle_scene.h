#ifndef SQUARE_SCENE_H_INCLUDED
#define SQUARE_SCENE_H_INCLUDED

#include "nvidia_demo/iscene.h"
#include "nvidia_demo/triangle.h"

#include <memory>

class SimpleTriangleScene : public IScene
{
public:
  SimpleTriangleScene(const opengl_core::gl_version& version);

  virtual ~SimpleTriangleScene();

  SimpleTriangleScene(const SimpleTriangleScene &) = delete;

  SimpleTriangleScene &operator=(const SimpleTriangleScene &) = delete;

  SimpleTriangleScene(SimpleTriangleScene &&) = delete;

  SimpleTriangleScene &operator=(SimpleTriangleScene &&) = delete;

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<Triangle> triangle_;
};

#endif
