#include "nvidia_demo/simpletriangle_scene.h"

#include "nvidia_demo/gl_functions.h"
#include "nvidia_demo/resource_loader.h"

#include <iostream>

SimpleTriangleScene::SimpleTriangleScene(
  const opengl_core::gl_version& version) :
  IScene(version)
{}

SimpleTriangleScene::~SimpleTriangleScene()
{}

bool SimpleTriangleScene::load()
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

  attributes_->use();
  shader_program_->use();

  GLint pos = glGetAttribLocation(shader_program_->id(), "position");
  GL_CALL(glGetAttribLocation)

  glEnableVertexAttribArray(pos);
  GL_CALL(glEnableVertexAttribArray)

  glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, 0);
  GL_CALL(glVertexAttribPointer)

  glDrawArrays(GL_TRIANGLES, 0, 3);
  GL_CALL(glDrawArrays)

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
