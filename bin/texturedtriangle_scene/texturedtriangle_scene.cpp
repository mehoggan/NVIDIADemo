#include "texturedtriangle_scene.h"

#include "nvidia_demo/gl_functions.h"

#include <iostream>

TexturedTriangleScene::TexturedTriangleScene(
  const opengl_core::gl_version &version) :
  IScene(version)
{}

TexturedTriangleScene::~TexturedTriangleScene()
{}

bool TexturedTriangleScene::load()
{
  bool ret = true;

  triangle_.reset(new TexturedTriangle(version_));

  std::unique_ptr<Textures> textures(new Textures({
    {
      "dog.png",
      {
        Textures::ImageConfigi {
          Textures::ParameterName::TEXTURE_WRAP_S,
          GL_CLAMP_TO_EDGE
        },
        Textures::ImageConfigi {
          Textures::ParameterName::TEXTURE_WRAP_T,
          GL_CLAMP_TO_EDGE
        },
        Textures::ImageConfigi {
          Textures::ParameterName::TEXTURE_MIN_FILTER,
          GL_LINEAR
        },
        Textures::ImageConfigi {
          Textures::ParameterName::TEXTURE_MAG_FILTER,
          GL_LINEAR
        },
      },
      {
      }
    }
  }));

  triangle_->load(
    "textured_triangle.vert",
    "textured_triangle.frag",
    std::move(textures));
  loaded_.store(true);

  return ret;
}

bool TexturedTriangleScene::render(std::uint16_t width, std::uint16_t height)
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

bool TexturedTriangleScene::destroy()
{
  bool ret = true;
  return ret;
}

bool TexturedTriangleScene::loaded() const
{
  return loaded_.load();
}
