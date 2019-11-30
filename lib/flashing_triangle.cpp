#include "nvidia_demo/flashing_triangle.h"

#include "nvidia_demo/resource_loader.h"

FlashingTriangle::FlashingTriangle(const opengl_core::gl_version &version) :
  start_(std::chrono::high_resolution_clock::now()),
  version_(version)
{}

FlashingTriangle::~FlashingTriangle()
{
  destroy();
}

bool FlashingTriangle::load()
{
  bool ret = true;

  attributes_.reset(
    new InterleavedVertexBuffer({
      glm::vec2 { +0.0f, +0.5f },
      glm::vec2 { +0.5f, -0.5f },
      glm::vec2 { -0.5f, -0.5f }},
      InterleavedVertexBuffer::Usage::STATIC_DRAW
    )
  );
  attributes_->use();

  auto v_source = ResourceLoader::load_shader(
    "flashing_triangle.vert", version_);
  vertex_shader_.reset(new Shader(v_source, Shader::Type::VERTEX));

  auto f_source = ResourceLoader::load_shader(
    "flashing_triangle.frag", version_);
  fragment_shader_.reset(new Shader(f_source, Shader::Type::FRAGMENT));

  shader_program_.reset(new ShaderProgram());
  shader_program_->add_shader(vertex_shader_);
  shader_program_->add_shader(fragment_shader_);
  shader_program_->link();

  return ret;
}

bool FlashingTriangle::draw()
{
  bool ret = true;
  attributes_->use();
  shader_program_->use();
  shader_program_->activate_attribute("position", 0ull, *(attributes_.get()));

  auto t_now = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::duration<float>>(
    t_now - start_).count();
  shader_program_->set_uniform3f(
    shader_program_->get_uniform_id("triangle_color"),
    (std::sin(time * 4.0f) + 1.0f) / 2.0f,
    0.0f,
    0.0f);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  GL_CALL(glDrawArrays)

  return ret;
}

bool FlashingTriangle::destroy()
{
  bool ret = true;

  return ret;
}
