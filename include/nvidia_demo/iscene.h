#ifndef ISCENE_H_INCLUDED
#define ISCENE_H_INCLUDED

#include <atomic>
#include <cstdint>

class IScene
{
public:
  IScene();

  virtual ~IScene();

  virtual bool load() = 0;

  virtual bool render(std::uint16_t width, std::uint16_t height) = 0;

  virtual bool destroy() = 0;

  virtual bool loaded() const = 0;

protected:
  std::atomic_bool loaded_;
};

#endif
