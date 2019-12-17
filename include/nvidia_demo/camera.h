#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <nvidia_demo/itransformable.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera : public ITransformable
{
public:
  struct PerspectiveParams
  {
    float radians_fov;
    uint16_t view_width;
    uint16_t view_height;
    float near_plane_distance;
    float far_plane_distance;

    float widthf() const;

    float heightf() const;
  };

public:
  Camera(
    const glm::vec3 &pos,
    const glm::vec3 &at,
    const glm::vec3 &world_up,
    const PerspectiveParams &params);

  virtual const glm::mat4 &model() const override;

  virtual void model(const glm::mat4 &model) override;

  const glm::mat4 &view() const;

  const glm::mat4 &proj() const;

  glm::mat4 mvp() const;

  const PerspectiveParams &perspective_params() const;

  void change_viewport(const PerspectiveParams &params);

private:
  glm::mat4 model_;
  glm::mat4 view_;
  glm::mat4 proj_;
  PerspectiveParams perspective_;
};

#endif
