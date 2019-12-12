cmake_minimum_required(VERSION 3.0.2)
include_directories(../)
include_directories(../include/)
message(STATUS "gtest_SOURCE_DIR = ${gtest_SOURCE_DIR}")
include_directories(${gtest_SOURCE_DIR}/include)

set(SRC
  ./application.cpp
  ./gl_functions.cpp
  ./idrawable.cpp
  ./interleaved_vertex_buffer.cpp
  ./iscene.cpp
  ./resource_loader.cpp
  ./shader.cpp
  ./shader_program.cpp
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
  GL
  pthread
)
add_dependencies(nvidia_demo gtest)
