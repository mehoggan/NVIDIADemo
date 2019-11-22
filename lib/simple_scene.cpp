#include <nvidia_demo/simple_scene.h>

#include "nvidia_demo/gl_functions.h"

SimpleScene::~SimpleScene()
{}

bool SimpleScene::load()
{
  bool ret = true;
  return ret;
}

bool SimpleScene::render()
{
  bool ret = true;
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  return ret;
}

bool SimpleScene::destroy()
{
  bool ret = true;
  return ret;
}
