cmake_minimum_required(VERSION 3.0.2)
include_directories(../../)
include_directories(../../include/)

set(SRC
  ./main.cpp
  ./texturedtriangle_scene.cpp
)

add_executable(texturedtriangle_scene ${SRC})

target_link_libraries(texturedtriangle_scene
  nvidia_demo
  pthread
)

add_custom_target(
  always_copy_shaders_texturedtriangle_scene ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(
  always_copy_shaders_texturedtriangle_scene
  texturedtriangle_scene
)

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/__header.h  # fake! ensure we run!
    ${CMAKE_CURRENT_BINARY_DIR}/header.h    # real header, we write.
  COMMAND
    ${CMAKE_COMMAND} -E echo "dummy" > ${CMAKE_CURRENT_BINARY_DIR}/header.h
)

add_custom_command(TARGET always_copy_shaders_texturedtriangle_scene
  COMMENT "Copy shaders adjacent to executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders
    ${CMAKE_BINARY_DIR}/bin/texturedtriangle_scene/shaders
)

add_custom_target(
  always_copy_textures_texturedtriangle_scene ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(
  always_copy_textures_texturedtriangle_scene
  texturedtriangle_scene
)

add_custom_command(TARGET always_copy_textures_texturedtriangle_scene
  COMMENT "Copy textures adjacent to executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/textures
    ${CMAKE_BINARY_DIR}/bin/texturedtriangle_scene/textures
)
