#include "nvidia_demo/iscene.h"

IScene::IScene(const opengl_core::gl_version &version) :
  loaded_(false),
  version_(version)
{}

IScene::~IScene()
{}
