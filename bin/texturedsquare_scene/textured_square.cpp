#include "nvidia_demo/rainbow_square.h"

#include "nvidia_demo/resource_loader.h"

RainbowSquare::RainbowSquare(const opengl_core::gl_version &version) :
  version_(version)
{}

RainbowSquare::~RainbowSquare()
{
  destroy();
}

bool RainbowSquare::load()
{
  bool ret = true;

  attributes_.reset(
    new InterleavedVertexBuffer({
      Supported::Vec2Col3 {
        Supported::Vec2 { -0.5f, +0.5f },
        Supported::Vec3 { 1.0f, 0.0f, 0.0f }
      },
      Supported::Vec2Col3 {
        Supported::Vec2 { +0.5f, +0.5f },
        Supported::Vec3 { 0.0f, 1.0f, 0.0f }
      },
      Supported::Vec2Col3 {
        Supported::Vec2 { +0.5f, -0.5f },
        Supported::Vec3 { 0.0f, 0.0f, 1.0f }
      },
      Supported::Vec2Col3 {
        Supported::Vec2 { -0.5f, -0.5f },
        Supported::Vec3 { 1.0f, 1.0f, 1.0f } }
      },
      { 0u, 1u, 2u, 2u, 3u, 0u },
      InterleavedVertexBuffer::Usage::STATIC_DRAW
    )
  );
  attributes_->use();

  auto v_source = ResourceLoader::load_shader(
    "rainbow_square.vert", version_);
  vertex_shader_.reset(new Shader(v_source, Shader::Type::VERTEX));

  auto f_source = ResourceLoader::load_shader(
    "rainbow_square.frag", version_);
  fragment_shader_.reset(new Shader(f_source, Shader::Type::FRAGMENT));

  shader_program_.reset(new ShaderProgram());
  shader_program_->add_shader(vertex_shader_);
  shader_program_->add_shader(fragment_shader_);
  shader_program_->link();

  return ret;
}

bool RainbowSquare::draw()
{
  bool ret = true;
  attributes_->use();
  shader_program_->use();
  shader_program_->activate_attribute("position", 0ull, *(attributes_.get()));
  shader_program_->activate_attribute("color", 1ull, *(attributes_.get()));

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  return ret;
}

bool RainbowSquare::destroy()
{
  bool ret = true;

  return ret;
}
