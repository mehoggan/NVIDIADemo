#ifndef ISCENE_H_INCLUDED
#define ISCENE_H_INCLUDED

#include "nvidia_demo/gl_functions.h"

#include <atomic>
#include <cstdint>

class IScene
{
public:
  explicit IScene(const opengl_core::gl_version &version);

  virtual ~IScene();

  virtual bool load() = 0;

  virtual bool render(std::uint16_t width, std::uint16_t height) = 0;

  virtual bool destroy() = 0;

  virtual bool loaded() const = 0;

protected:
  std::atomic_bool loaded_;
  opengl_core::gl_version version_;
};

#endif
