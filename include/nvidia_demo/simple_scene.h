#ifndef SIMPLE_SCENE_H_INCLUDED
#define SIMPLE_SCENE_H_INCLUDED

#include "nvidia_demo/iscene.h"

class SimpleScene : public IScene
{
public:
  SimpleScene() = default;

  virtual ~SimpleScene();

  virtual bool load() override;

  virtual bool render() override;

  virtual bool destroy() override;
};

#endif
