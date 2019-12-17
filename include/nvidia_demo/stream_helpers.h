#ifndef STREAM_HELPERS_H_INCLUDED
#define STREAM_HELPERS_H_INCLUDED

#include <glm/glm.hpp>

#include <iomanip>
#include <iostream>

std::ostream &operator<<(std::ostream &out, const glm::mat4 &m);

#endif
