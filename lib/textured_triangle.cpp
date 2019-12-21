#include "nvidia_demo/textured_triangle.h"

#include "nvidia_demo/resource_loader.h"

TexturedTriangle::TexturedTriangle(const opengl_core::gl_version &version) :
  IRenderable(version),
  vertices_({
   BaseAttributes_t {
     Supported::Vec3{ -0.5, -0.5, +0.0 },
     Supported::Vec2{ 0.0f, 0.0f },
   },
   BaseAttributes_t {
     Supported::Vec3{ +0.5, -0.5, +0.0 },
     Supported::Vec2{ 1.0f, 0.0f },
   },
   BaseAttributes_t {
     Supported::Vec3{ +0.5f, +0.5f, +0.0f },
     Supported::Vec2{ 1.0f, 1.0f }
   }
  })
{}

TexturedTriangle::TexturedTriangle(
  const opengl_core::gl_version &version,
  std::array<BaseAttributes_t, 3> &vertices) :
  IRenderable(version),
  vertices_(vertices)
{}

TexturedTriangle::~TexturedTriangle()
{}

bool TexturedTriangle::load()
{
  if (vertices_.empty()) {
    throw std::runtime_error("Cannot have triangle with 0 vertices.");
  }
  
  return load(vertices_);
}

bool TexturedTriangle::draw()
{
  bool ret = true;

  attributes_->use();
  program_->use();
  program_->activate_attribute("position", 0ull, *(attributes_.get()));
  program_->activate_attribute("texcoord2d", 1ull, *(attributes_.get()));

  textures_->activate(0);
  GLint tex_id = program_->get_uniform_id("tex");
  program_->set_uniform1i(tex_id, 0);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  GL_CALL(glDrawArrays)
  return ret;
}

bool TexturedTriangle::destroy()
{
  bool ret = true;

  attributes_.reset(nullptr);
  textures_.reset(nullptr);

  return ret;
}

const glm::mat4 &TexturedTriangle::model() const
{
  return model_;
}

void TexturedTriangle::model(const glm::mat4 &model)
{
  model_ = model;
}

bool TexturedTriangle::load(const std::array<BaseAttributes_t, 3> &attributes)
{
  std::unique_ptr<Textures> textures(new Textures({
    {
      "default.png",
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

  return load(
    attributes,
    "triangle.vert",
    "triangle.frag",
    std::move(textures));
}

bool TexturedTriangle::load(
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename,
  std::unique_ptr<Textures> &&textures)
{
  return load(
    vertices_,
    vertex_shader_filename,
    fragment_shader_filename,
    std::move(textures));
}

bool TexturedTriangle::load(
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

  textures_ = std::move(textures);
  vertices_ = attributes;

  return ret;
}
const std::array<TexturedTriangle::BaseAttributes_t, 3> &
TexturedTriangle::vertices() const
{
  return vertices_;
}

bool TexturedTriangle::is_valid() const
{
  return not (version_.major == 0);
}
