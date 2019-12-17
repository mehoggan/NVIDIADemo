#include "textured_square.h"

#include "nvidia_demo/resource_loader.h"
#include "nvidia_demo/stream_helpers.h"

#include <glm/gtc/type_ptr.hpp>

#include <iomanip>

TexturedSquare::TexturedSquare(const opengl_core::gl_version &version) :
  ITransformable(),
  version_(version),
  camera_(
    { +0.0f, -2.0f, +2.0f },
    { +0.0f, +0.0f, +0.0f },
    { +0.0f, +1.0f, +0.0f },
    { glm::radians(45.0), 800, 600, 1.0f, 10.0f }),
  rotation_(std::chrono::high_resolution_clock::now())
{}

TexturedSquare::~TexturedSquare()
{
  destroy();
}

const glm::mat4 &TexturedSquare::model() const
{
  return model_;
}

void TexturedSquare::model(const glm::mat4 &model)
{
  model_ = model;
}

bool TexturedSquare::load()
{
  bool ret = true;

  attributes_.reset(
    new InterleavedVertexBuffer({
      Supported::Vec2Col3Tex2 {
        Supported::Vec2 { -0.5f, +0.5f },
        Supported::Vec3 { 1.0f, 0.0f, 0.0f },
        Supported::Vec2 { +0.0f, +0.0f }
      },
      Supported::Vec2Col3Tex2 {
        Supported::Vec2 { +0.5f, +0.5f },
        Supported::Vec3 { 1.0f, 1.0f, 1.0f },
        Supported::Vec2 { +1.0f, +0.0f }
      },
      Supported::Vec2Col3Tex2 {
        Supported::Vec2 { +0.5f, -0.5f },
        Supported::Vec3 { 0.0f, 1.0f, 0.0f },
        Supported::Vec2 { +1.0f, +1.0f }
      },
      Supported::Vec2Col3Tex2 {
        Supported::Vec2 { -0.5f, -0.5f },
        Supported::Vec3 { 1.0f, 1.0f, 1.0f },
        Supported::Vec2 { +0.0f, +1.0f }
      }
    },
    { 0u, 1u, 2u, 2u, 3u, 0u },
    InterleavedVertexBuffer::Usage::STATIC_DRAW));
  attributes_->use();

  auto v_source = ResourceLoader::load_shader(
    "textured_square.vert", version_);
  vertex_shader_.reset(new Shader(v_source, Shader::Type::VERTEX));

  auto f_source = ResourceLoader::load_shader(
    "textured_square.frag", version_);
  fragment_shader_.reset(new Shader(f_source, Shader::Type::FRAGMENT));

  shader_program_.reset(new ShaderProgram());
  shader_program_->add_shader(vertex_shader_);
  shader_program_->add_shader(fragment_shader_);
  shader_program_->link();

  textures_.reset(new Textures({
    {
      "cat.png",
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
    },
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

  return ret;
}

bool TexturedSquare::draw()
{
  bool ret = true;
  attributes_->use();
  shader_program_->use();
  shader_program_->activate_attribute("position", 0ull, *(attributes_.get()));
  shader_program_->activate_attribute("color", 1ull, *(attributes_.get()));
  shader_program_->activate_attribute("texcoord", 2ull, *(attributes_.get()));

  textures_->activate(0);
  GLint kitten_id = shader_program_->get_uniform_id("texKitten");
  shader_program_->set_uniform1i(kitten_id, 0);

  textures_->activate(1);
  GLint puppy_id = shader_program_->get_uniform_id("texPuppy");
  shader_program_->set_uniform1i(puppy_id, 1);

  compute_transform();
  camera_.model(model());
  GLint mvp_id = shader_program_->get_uniform_id("mvp");
  shader_program_->set_uniform_matrix4fv(mvp_id, camera_.mvp());

  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  return ret;
}

bool TexturedSquare::destroy()
{
  bool ret = true;

  return ret;
}

void TexturedSquare::compute_transform()
{
  auto t_now = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::duration<float>>(
    t_now - rotation_).count();

  model_ = glm::mat4(1.0f);
  model_ = glm::rotate(
    model_,
    time * glm::radians(180.0f),
    glm::vec3(0.0f, 0.0f, 1.0f));
}
