#include "simple_triangle.h"

#include "nvidia_demo/resource_loader.h"

SimpleTriangle::SimpleTriangle(const opengl_core::gl_version &version) :
  version_(version)
{}

SimpleTriangle::~SimpleTriangle()
{
  destroy();
}

bool SimpleTriangle::load()
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
    "simple_triangle.vert", version_);
  vertex_shader_.reset(new Shader(v_source, Shader::Type::VERTEX));

  auto f_source = ResourceLoader::load_shader(
    "simple_triangle.frag", version_);
  fragment_shader_.reset(new Shader(f_source, Shader::Type::FRAGMENT));

  shader_program_.reset(new ShaderProgram());
  shader_program_->add_shader(vertex_shader_);
  shader_program_->add_shader(fragment_shader_);
  shader_program_->link();

  return ret;
}

bool SimpleTriangle::draw()
{
  bool ret = true;

  attributes_->use();
  shader_program_->use();
  shader_program_->activate_attribute("position", 0ull, *(attributes_.get()));

  glDrawArrays(GL_TRIANGLES, 0, 3);
  GL_CALL(glDrawArrays)

  return ret;
}

bool SimpleTriangle::destroy()
{
  bool ret = true;

  return ret;
}
