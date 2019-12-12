cmake_minimum_required(VERSION 3.0.2)
include_directories(../../)
include_directories(../../include/)

set(SRC
  ./main.cpp
  ./simple_scene.cpp
)

add_executable(simple_scene ${SRC})

target_link_libraries(simple_scene
  nvidia_demo
  pthread
)
