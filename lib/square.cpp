#include "nvidia_demo/square.h"

#include "nvidia_demo/resource_loader.h"
#include "nvidia_demo/triangle_stream.h"

Square::Square(const opengl_core::gl_version &version) :
  IRenderable(version) 
{
  std::unique_ptr<Triangle> tri1(
    new Triangle(
      version,
      {
        Supported::Vec3Col3 {
          Supported::Vec3 { -0.5, -0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        },
        Supported::Vec3Col3 {
          Supported::Vec3 { +0.5, -0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        },
        Supported::Vec3Col3 {
          Supported::Vec3 { +0.5, +0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        }
      }
    )
  );

  std::unique_ptr<Triangle> tri2(
    new Triangle(
      version,
      {
        Supported::Vec3Col3 {
          Supported::Vec3 { +0.5, +0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        },
        Supported::Vec3Col3 {
          Supported::Vec3 { -0.5, +0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        },
        Supported::Vec3Col3 {
          Supported::Vec3 { -0.5, -0.5, +0.0 },
          Supported::Col3 { 1.0f, 1.0f, 1.0f }
        }
      }
    )
  );

  triangles_ = std::array<std::unique_ptr<Triangle>, 2> {
    std::move(tri1),
    std::move(tri2)
  };
}

Square::~Square()
{}

bool Square::load()
{
  bool ret = true;

  if (triangles_.size() != 2) {
    throw std::runtime_error("Cannot have triangle without two triangles.");
  }

  load("square.vert", "square.frag");
  
  return ret;
}

bool Square::draw()
{
  bool ret = true;

  attributes_->use();
  program_->use();
  program_->activate_attribute("position", 0ull, *(attributes_.get()));

  glDrawArrays(GL_TRIANGLES, 0, 6);
  GL_CALL(glDrawArrays)
  return ret;
}

bool Square::destroy()
{
  bool ret = true;

  attributes_.reset(nullptr);

  return ret;
}

const glm::mat4 &Square::model() const
{
  return model_;
}

void Square::model(const glm::mat4 &model)
{
  model_ = model;
}

bool Square::load(
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename)
{
  bool ret = true;

  Square clone(version_, triangles_);
  std::vector<std::unique_ptr<Triangle>> triangles;
  for (std::unique_ptr<Triangle> &triangle : triangles_) {
    triangles.push_back(std::move(triangle));
  }
  std::unique_ptr<InterleavedVertexBuffer> vbo = TriangleStream::upload(
    triangles,
    InterleavedVertexBuffer::Usage::STATIC_DRAW);
  attributes_ = std::move(vbo);
  attributes_->use();

  auto v_source = ResourceLoader::load_shader(
    vertex_shader_filename, version_);
  std::unique_ptr<Shader> vertex_shader(
    new Shader(v_source, Shader::Type::VERTEX));

  auto f_source = ResourceLoader::load_shader(
    fragment_shader_filename, version_);
  std::unique_ptr<Shader> fragment_shader(
    new Shader(f_source, Shader::Type::FRAGMENT));

  program_.reset(new ShaderProgram());
  program_->add_shader(vertex_shader);
  program_->add_shader(fragment_shader);
  program_->link();

  return ret;
}

const std::array<std::unique_ptr<Triangle>, 2> &Square::triangles() const
{
  return triangles_;
}

bool Square::is_valid() const
{
  return not (version_.major == 0);
}

Square::Square(
  const opengl_core::gl_version &version,
  const std::array<std::unique_ptr<Triangle>, 2> &clone) :
  IRenderable(version)
{
  triangles_[0].reset(new Triangle(version_, clone[0]->vertices()));
  triangles_[1].reset(new Triangle(version_, clone[1]->vertices()));
}
