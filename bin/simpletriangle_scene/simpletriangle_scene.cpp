#include "simpletriangle_scene.h"

#include "nvidia_demo/gl_functions.h"

#include <iostream>

SimpleTriangleScene::SimpleTriangleScene(
  const opengl_core::gl_version &version) :
  IScene(version)
{}

SimpleTriangleScene::~SimpleTriangleScene()
{}

bool SimpleTriangleScene::load()
{
  bool ret = true;

  triangle_.reset(new Triangle(version_));

    
  triangle_->load("simple_triangle.vert", "simple_triangle.frag");
  loaded_.store(true);

  return ret;
}

bool SimpleTriangleScene::render(std::uint16_t width, std::uint16_t height)
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

  triangle_->draw();

  return ret;
}

bool SimpleTriangleScene::destroy()
{
  bool ret = true;
  return ret;
}

bool SimpleTriangleScene::loaded() const
{
  return loaded_.load();
}
