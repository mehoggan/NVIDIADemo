#ifndef SQUARE_SCENE_H_INCLUDED
#define SQUARE_SCENE_H_INCLUDED

#include "nvidia_demo/iscene.h"
#include "nvidia_demo/textured_triangle.h"

#include <memory>

class TexturedTriangleScene : public IScene
{
public:
  TexturedTriangleScene(const opengl_core::gl_version& version);

  virtual ~TexturedTriangleScene();

  TexturedTriangleScene(const TexturedTriangleScene &) = delete;

  TexturedTriangleScene &operator=(const TexturedTriangleScene &) = delete;

  TexturedTriangleScene(TexturedTriangleScene &&) = delete;

  TexturedTriangleScene &operator=(TexturedTriangleScene &&) = delete;

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<TexturedTriangle> triangle_;
};

#endif
