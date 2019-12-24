#include "texturedsquare_scene.h"

#include "nvidia_demo/gl_functions.h"

#include <iostream>

TexturedSquareScene::TexturedSquareScene(
  const opengl_core::gl_version &version) :
  IScene(version)
{}

TexturedSquareScene::~TexturedSquareScene()
{}

bool TexturedSquareScene::load()
{
  bool ret = true;

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

  square_.reset(new TexturedSquare(version_));
  square_->load(
    "textured_square.vert",
    "textured_square.frag",
    std::move(textures));

  loaded_.store(true);

  return ret;
}

bool TexturedSquareScene::render(std::uint16_t width, std::uint16_t height)
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

bool TexturedSquareScene::destroy()
{
  bool ret = true;
  return ret;
}

bool TexturedSquareScene::loaded() const
{
  return loaded_.load();
}
