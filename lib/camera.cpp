#include "nvidia_demo/camera.h"

#include "nvidia_demo/stream_helpers.h"

#include <stdexcept>

float Camera::PerspectiveParams::widthf() const
{
  return static_cast<float>(view_width);
}

float Camera::PerspectiveParams::heightf() const
{
  return static_cast<float>(view_height);
}

Camera::Camera(
  const glm::vec3 &pos,
  const glm::vec3 &at,
  const glm::vec3 &world_up,
  const PerspectiveParams &params)
{
  // Note: model will default to identity.

  view_ = glm::lookAt(pos, at, world_up);
  change_viewport(params);
}

void Camera::model(const glm::mat4 &model)
{
  model_ = model;
}

const glm::mat4 &Camera::model() const
{
  return model_;
}

const glm::mat4 &Camera::view() const
{
  return view_;
}

const glm::mat4 &Camera::proj() const
{
  return proj_;
}

glm::mat4 Camera::mvp() const
{
  return proj_ * view_ * model_;
}

void Camera::change_viewport(const PerspectiveParams &params)
{
  perspective_ = params;

  if (params.view_height == 0) {
    throw std::runtime_error("Invalid height for viewport specified.");
  }

  proj_ = glm::perspective(
    params.radians_fov,
    params.widthf() / params.heightf(),
    params.near_plane_distance,
    params.far_plane_distance);
}
