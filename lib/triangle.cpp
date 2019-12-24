#include "nvidia_demo/triangle.h"

#include "nvidia_demo/resource_loader.h"

Triangle::Triangle(const opengl_core::gl_version &version) :
  IRenderable(version),
  vertices_({
   Supported::Vec3Col3 {
     Supported::Vec3{ -0.5, -0.5, +0.0 },
     Supported::Vec3{ 1.0f, 1.0f, 1.0f },
   },
   Supported::Vec3Col3 {
     Supported::Vec3{ +0.5, -0.5, +0.0 },
     Supported::Vec3{ 1.0f, 1.0f, 1.0f },
   },
   Supported::Vec3Col3 {
     Supported::Vec3{ +0.0f, +0.5f, +0.0f },
     Supported::Vec3{ 1.0f, 1.0f, 1.0f }
   }
  })
{}

Triangle::Triangle(
  const opengl_core::gl_version &version,
  const std::array<BaseAttributes_t, 3> &vertices) :
  IRenderable(version),
  vertices_(vertices)
{}

Triangle::~Triangle()
{}

bool Triangle::load()
{
  if (vertices_.empty()) {
    throw std::runtime_error("Cannot have triangle with 0 vertices.");
  }
  
  return load(vertices_);
}

bool Triangle::draw()
{
  bool ret = true;

  attributes_->use();
  program_->use();
  program_->activate_attribute("position", 0ull, *(attributes_.get()));

  glDrawArrays(GL_TRIANGLES, 0, 3);
  GL_CALL(glDrawArrays)
  return ret;
}

bool Triangle::destroy()
{
  bool ret = true;

  attributes_.reset(nullptr);

  return ret;
}

const glm::mat4 &Triangle::model() const
{
  return model_;
}

void Triangle::model(const glm::mat4 &model)
{
  model_ = model;
}

bool Triangle::load(const std::array<BaseAttributes_t, 3> &attributes)
{
  return load(
    attributes,
    "triangle.vert",
    "triangle.frag",
    nullptr);
}

bool Triangle::load(
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename)
{
  return load(
    vertices_,
    vertex_shader_filename,
    fragment_shader_filename);
}

bool Triangle::load(
  const std::array<BaseAttributes_t, 3> &attributes,
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename)
{
  return load(
    attributes,
    vertex_shader_filename,
    fragment_shader_filename,
    nullptr);
}

bool Triangle::load(
  const std::array<BaseAttributes_t, 3> &attributes,
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename,
  std::unique_ptr<Textures> &&textures)
{
  bool ret = true;

  std::vector<BaseAttributes_t> attrib(attributes.begin(), attributes.end());
  attributes_.reset(new InterleavedVertexBuffer(
    attrib,
    InterleavedVertexBuffer::Usage::STATIC_DRAW));
  attributes_->use();

  std::unique_ptr<Shader> vertex_shader;
  if (not vertex_shader_filename.empty()) {
    auto v_source = ResourceLoader::load_shader(
      vertex_shader_filename,
      version_);
    vertex_shader.reset(new Shader(v_source, Shader::Type::VERTEX));
  }

  std::unique_ptr<Shader> fragment_shader;
  if (not fragment_shader_filename.empty()) {
    auto f_source = ResourceLoader::load_shader(
      fragment_shader_filename,
      version_);
    fragment_shader.reset(new Shader(f_source, Shader::Type::FRAGMENT));
  }

  if (vertex_shader && fragment_shader) {
    program_.reset(new ShaderProgram());
    program_->add_shader(vertex_shader);
    program_->add_shader(fragment_shader);
    program_->link();
  }

  if (textures) {
    textures_ = std::move(textures);
  }

  vertices_ = attributes;

  return ret;
}
const std::array<Triangle::BaseAttributes_t, 3> &Triangle::vertices() const
{
  return vertices_;
}

bool Triangle::is_valid() const
{
  return not (version_.major == 0);
}
