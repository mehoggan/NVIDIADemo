#ifndef RAINBOW_SQUARE_SCENE_H_INCLUDED
#define RAINBOW_SQUARE_SCENE_H_INCLUDED

#include "textured_square.h"

#include "nvidia_demo/iscene.h"

#include <memory>

class TexturedSquareScene : public IScene
{
public:
  TexturedSquareScene(const opengl_core::gl_version& version);

  virtual ~TexturedSquareScene();

  TexturedSquareScene(const TexturedSquareScene &) = delete;

  TexturedSquareScene &operator=(const TexturedSquareScene &) = delete;

  TexturedSquareScene(TexturedSquareScene &&) = delete;

  TexturedSquareScene &operator=(TexturedSquareScene &&) = delete;

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<TexturedSquare> square_;
};

#endif
