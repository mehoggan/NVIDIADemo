#ifndef ISCENE_H_INCLUDED
#define ISCENE_H_INCLUDED

class IScene
{
public:
  IScene() = default;

  virtual ~IScene();

  virtual bool load() = 0;

  virtual bool render() = 0;

  virtual bool destroy() = 0;
};

#endif
