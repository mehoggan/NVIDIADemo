#ifndef ITRANSFORMABLE_H_INCLUDED
#define ITRANSFORMABLE_H_INCLUDED

#include <glm/glm.hpp>

class ITransformable
{
public:
  ITransformable();

  virtual ~ITransformable();

  virtual const glm::mat4 &model() const = 0;

  virtual void model(const glm::mat4 &model) = 0;

protected:
  glm::mat4 model_;
};

#endif
