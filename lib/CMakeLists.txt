cmake_minimum_required(VERSION 3.0.2)
include_directories(../)
include_directories(../include/)
message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")
include_directories(${gtest_SOURCE_DIR}/include)

set(SRC
  ./application.cpp
  ./camera.cpp
  ./gl_functions.cpp
  ./idrawable.cpp
  ./interleaved_vertex_buffer.cpp
  ./irenderable.cpp
  ./iscene.cpp
  ./itransformable.cpp
  ./resource_loader.cpp
  ./shader.cpp
  ./shader_program.cpp
  ./square.cpp
  ./stream_helpers.cpp
  ./textured_square.cpp
  ./textured_triangle.cpp
  ./textures.cpp
  ./triangle.cpp
  ./triangle_stream.cpp
)

if (BUILD_SHARED_LIBS)
  add_library(nvidia_demo SHARED ${SRC})
  add_definitions(-DDAGTASKS_SHARED -DDAGTASKS_EXPORTS)
else()
  add_library(nvidia_demo STATIC ${SRC})
  add_definitions(-DDAGTASKS_STATIC)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/win32.cmake)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall \
    -fno-strict-aliasing")
endif()

target_link_libraries(nvidia_demo
  SDL2-2.0
  png
  GL
  pthread
)
add_dependencies(nvidia_demo gtest)

add_custom_target(
  always_copy_lib_shaders ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(
  always_copy_lib_shaders
  nvidia_demo
)

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/__header.h  # fake! ensure we run!
    ${CMAKE_CURRENT_BINARY_DIR}/header.h    # real header, we write.
  COMMAND
    ${CMAKE_COMMAND} -E echo "dummy" > ${CMAKE_CURRENT_BINARY_DIR}/header.h
)

add_custom_command(TARGET always_copy_lib_shaders
  COMMENT "Copy shaders adjacent to executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders
    ${CMAKE_BINARY_DIR}/bin/shaders
)

add_custom_target(
  always_copy_lib_textures ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(
  always_copy_lib_textures
  nvidia_demo
)

add_custom_command(TARGET always_copy_lib_textures
  COMMENT "Copy textures adjacent to executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/textures
    ${CMAKE_BINARY_DIR}/bin/textures
)
