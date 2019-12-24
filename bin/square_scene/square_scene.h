#ifndef SQUARE_SCENE_H_INCLUDED
#define SQUARE_SCENE_H_INCLUDED

#include <nvidia_demo/iscene.h>
#include <nvidia_demo/square.h>

#include <memory>

class SquareScene : public IScene
{
public:
  SquareScene(const opengl_core::gl_version& version);

  virtual ~SquareScene();

  SquareScene(const SquareScene &) = delete;

  SquareScene &operator=(const SquareScene &) = delete;

  SquareScene(SquareScene &&) = delete;

  SquareScene &operator=(SquareScene &&) = delete;

  virtual bool load() override;

  virtual bool render(std::uint16_t width, std::uint16_t height) override;

  virtual bool destroy() override;

  virtual bool loaded() const override;

private:
  std::unique_ptr<Square> square_;
};

#endif
