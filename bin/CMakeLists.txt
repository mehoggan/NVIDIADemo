cmake_minimum_required(VERSION 3.0.2)
include_directories(../)
include_directories(../include/)

set(SRC
  main.cpp
)

add_executable(nvidia_demo_runner ${SRC})

target_link_libraries(nvidia_demo_runner
  nvidia_demo
  GL
  SDL2-2.0
  pthread
)
