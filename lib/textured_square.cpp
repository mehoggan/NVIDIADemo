#include "nvidia_demo/textured_square.h"

#include "nvidia_demo/resource_loader.h"
#include "nvidia_demo/triangle_stream.h"

TexturedSquare::TexturedSquare(const opengl_core::gl_version &version) :
  IRenderable(version) 
{
  std::unique_ptr<TexturedTriangle> tri1(
    new TexturedTriangle(
      version,
      {
        Supported::Vec3Tex2 {
          Supported::Vec3 { -0.5, -0.5, +0.0 },
          Supported::Tex2 { 0.0f, 0.0f }
        },
        Supported::Vec3Tex2 {
          Supported::Vec3 { +0.5, -0.5, +0.0 },
          Supported::Tex2 { 1.0f, 0.0f }
        },
        Supported::Vec3Tex2 {
          Supported::Vec3 { +0.5, +0.5, +0.0 },
          Supported::Tex2 { 1.0f, 1.0f }
        }
      }
    )
  );

  std::unique_ptr<TexturedTriangle> tri2(
    new TexturedTriangle(
      version,
      {
        Supported::Vec3Tex2 {
          Supported::Vec3 { +0.5, +0.5, +0.0 },
          Supported::Tex2 { 1.0f, 1.0f }
        },
        Supported::Vec3Tex2 {
          Supported::Vec3 { -0.5, +0.5, +0.0 },
          Supported::Tex2 { 0.0f, 1.0f }
        },
        Supported::Vec3Tex2 {
          Supported::Vec3 { -0.5, -0.5, +0.0 },
          Supported::Tex2 { 0.0f, 0.0f }
        }
      }
    )
  );

  triangles_ = std::array<std::unique_ptr<TexturedTriangle>, 2> {
    std::move(tri1),
    std::move(tri2)
  };
}

TexturedSquare::~TexturedSquare()
{}

bool TexturedSquare::load()
{
  bool ret = true;

  if (triangles_.size() != 2) {
    throw std::runtime_error("Cannot have triangle without two triangles.");
  }

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

  load("textured_square.vert", "textured_square.frag", std::move(textures));
  
  return ret;
}

bool TexturedSquare::draw()
{
  bool ret = true;

  attributes_->use();
  program_->use();
  program_->activate_attribute("position", 0ull, *(attributes_.get()));
  program_->activate_attribute("texcoord2d", 1ull, *(attributes_.get()));

  textures_->activate(0);
  GLint tex_id = program_->get_uniform_id("tex");
  program_->set_uniform1i(tex_id, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
  GL_CALL(glDrawArrays)

  return ret;
}

bool TexturedSquare::destroy()
{
  bool ret = true;

  attributes_.reset(nullptr);

  return ret;
}

const glm::mat4 &TexturedSquare::model() const
{
  return model_;
}

void TexturedSquare::model(const glm::mat4 &model)
{
  model_ = model;
}

bool TexturedSquare::load(
  const std::string &vertex_shader_filename,
  const std::string &fragment_shader_filename,
  std::unique_ptr<Textures> &&textures)
{
  bool ret = true;

  TexturedSquare clone(version_, triangles_);
  std::vector<std::unique_ptr<TexturedTriangle>> triangles;
  for (std::unique_ptr<TexturedTriangle> &triangle : triangles_) {
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

  textures_ = std::move(textures);

  return ret;
}

const std::array<std::unique_ptr<TexturedTriangle>, 2> &
TexturedSquare::triangles() const
{
  return triangles_;
}

bool TexturedSquare::is_valid() const
{
  return not (version_.major == 0);
}

TexturedSquare::TexturedSquare(
  const opengl_core::gl_version &version,
  const std::array<std::unique_ptr<TexturedTriangle>, 2> &clone) :
  IRenderable(version)
{
  triangles_[0].reset(new TexturedTriangle(version_, clone[0]->vertices()));
  triangles_[1].reset(new TexturedTriangle(version_, clone[1]->vertices()));
}
