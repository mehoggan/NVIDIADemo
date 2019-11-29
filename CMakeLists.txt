cmake_minimum_required(VERSION 3.0.2)
project(NVIDIADemo)

option(BUILD_SHARED_LIBS "Build shared libraries over static library." ON)
option(NVIDIA_DEMO_TESTS "Build unit tests." ON)
option(NVIDIA_DEMO_BINDINGS "Build all bindings for the native library." ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -fexceptions")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_MACOSX_RPATH 1)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/c++17.cmake)

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/googletest-src/googletest/include)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.libsdl.txt.in
  ${CMAKE_BINARY_DIR}/libsdl-download/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/libsdl.cmake)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/libsdl-src/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/libsdl-build)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.glm.txt.in
  ${CMAKE_BINARY_DIR}/glm-download/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/glm.cmake)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/glm-src)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/glm-build/glm)

add_subdirectory(lib)

if(NVIDIA_DEMO_TESTS)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.googletest.txt.in
    ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
  include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/googletest.cmake)
  add_subdirectory(tests)
endif()

add_subdirectory(bin)
