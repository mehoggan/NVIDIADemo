#include "nvidia_demo/stream_helpers.h"

#include <glm/gtx/string_cast.hpp>

std::ostream &operator<<(std::ostream &out, const glm::mat4 &m)
{
  out << glm::to_string(m);
  return out;
}
