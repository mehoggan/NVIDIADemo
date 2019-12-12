#include "nvidia_demo/rainbowsquare_scene.h"

#include "nvidia_demo/gl_functions.h"

#include <iostream>

RainbowSquareScene::RainbowSquareScene(
  const opengl_core::gl_version &version) :
  IScene(version)
{}

RainbowSquareScene::~RainbowSquareScene()
{}

bool RainbowSquareScene::load()
{
  bool ret = true;

  square_.reset(new RainbowSquare(version_));
  square_->load();

  loaded_.store(true);

  return ret;
}

bool RainbowSquareScene::render(std::uint16_t width, std::uint16_t height)
{
  bool ret = true;

  if (not loaded_.load()) {
    load();
    loaded_.store(true);
  }

  glViewport(0, 0, width, height);
  GL_CALL(glViewport)

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  GL_CALL(glClear)

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  GL_CALL(glClearColor)

  square_->draw();

  return ret;
}

bool RainbowSquareScene::destroy()
{
  bool ret = true;
  return ret;
}

bool RainbowSquareScene::loaded() const
{
  return loaded_.load();
}
