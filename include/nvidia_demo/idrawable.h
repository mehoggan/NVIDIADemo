#ifndef IDRAWABLE_H_INCLUDED
#define IDRAWABLE_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

class IDrawable
{
public:
  IDrawable() = default;

  virtual ~IDrawable();

  virtual bool load() = 0;

  virtual bool draw() = 0;

  virtual bool destroy() = 0;
};

#endif
