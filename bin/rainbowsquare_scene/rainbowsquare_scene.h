#ifndef RAINBOW_SQUARE_SCENE_H_INCLUDED
#define RAINBOW_SQUARE_SCENE_H_INCLUDED

#include "rainbow_square.h"

#include "nvidia_demo/iscene.h"

#include <memory>

class RainbowSquareScene : public IScene
{
public:
  RainbowSquareScene(const opengl_core::gl_version& version);

  virtual ~RainbowSquareScene();

  RainbowSquareScene(const RainbowSquareScene &) = delete;

  RainbowSquareScene &operator=(const RainbowSquareScene &) = delete;

  RainbowSquareScene(RainbowSquareScene &&) = delete;

  RainbowSquareScene &operator=(RainbowSquareScene &&) = delete;

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<RainbowSquare> square_;
};

#endif
