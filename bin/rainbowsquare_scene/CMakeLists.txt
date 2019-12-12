cmake_minimum_required(VERSION 3.0.2)
include_directories(../../)
include_directories(../../include/)

set(SRC
  ./main.cpp
  ./rainbow_square.cpp
  ./rainbowsquare_scene.cpp
)

add_executable(rainbowsquare_scene ${SRC})

target_link_libraries(rainbowsquare_scene
  nvidia_demo
  pthread
)

add_custom_target(
  always_copy_shaders_rainbowsquare_scene ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(always_copy_shaders_rainbowsquare_scene rainbowsquare_scene)

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/__header.h  # fake! ensure we run!
    ${CMAKE_CURRENT_BINARY_DIR}/header.h    # real header, we write.
  COMMAND
    ${CMAKE_COMMAND} -E echo "dummy" > ${CMAKE_CURRENT_BINARY_DIR}/header.h
)

add_custom_command(TARGET always_copy_shaders_rainbowsquare_scene
  COMMENT "Copy shaders adjacent to executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders
    ${CMAKE_BINARY_DIR}/bin/rainbowsquare_scene/shaders
)
