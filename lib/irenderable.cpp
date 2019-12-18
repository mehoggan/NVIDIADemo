#include "nvidia_demo/irenderable.h"

IRenderable::IRenderable(const opengl_core::gl_version &version) :
  version_(version)
{}

IRenderable::~IRenderable()
{}
