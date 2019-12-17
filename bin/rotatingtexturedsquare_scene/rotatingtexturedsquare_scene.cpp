#include "rotatingtexturedsquare_scene.h"

#include "nvidia_demo/gl_functions.h"

#include <iostream>

RotatingTexturedSquareScene::RotatingTexturedSquareScene(
  const opengl_core::gl_version &version) :
  IScene(version)
{}

RotatingTexturedSquareScene::~RotatingTexturedSquareScene()
{}

bool RotatingTexturedSquareScene::load()
{
  bool ret = true;

  square_.reset(new TexturedSquare(version_));
  square_->load();

  loaded_.store(true);

  return ret;
}

bool RotatingTexturedSquareScene::render(
  std::uint16_t width,
  std::uint16_t height)
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

bool RotatingTexturedSquareScene::destroy()
{
  bool ret = true;
  return ret;
}

bool RotatingTexturedSquareScene::loaded() const
{
  return loaded_.load();
}
