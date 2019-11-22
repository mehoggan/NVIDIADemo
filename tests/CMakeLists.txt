cmake_minimum_required(VERSION 3.0.2)

find_program(valgrind REQUIRED)
set(CTEST_MEMORYCHECK_COMMAND "/usr/bin/valgrind") 
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes
  --leak-check=full")
include(CTest)
enable_testing()

add_test(unit_test unit_test --report_level=no --log_level=all
  --output_format=xml --log_sink=${CMAKE_BINARY_DIR}/test_logs/${name}.xml)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall \
  -fno-strict-aliasing")

include_directories(${Boost_INCLUDE_DIRS})

add_executable(unit_test
  main.cxx
)

target_link_libraries(unit_test
  gtest
  gtest_main
  gmock
  gmock_main
  pthread
)

include_directories(../include)
include_directories(../)
include_directories(${gtest_SOURCE_DIR}/include)
include_directories(./utils)

add_custom_target(
  my_custom_target_that_always_runs ALL
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__header.h
)
add_dependencies(my_custom_target_that_always_runs unit_test)

add_custom_command(
  OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/__header.h  # fake! ensure we run!
    ${CMAKE_CURRENT_BINARY_DIR}/header.h    # real header, we write.
  COMMAND
    ${CMAKE_COMMAND} -E echo "dummy" > ${CMAKE_CURRENT_BINARY_DIR}/header.h
)

add_custom_command(TARGET my_custom_target_that_always_runs
  COMMENT "Copy unit test data adjacent to unit test executable."
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/test_data/*
    ${CMAKE_CURRENT_BINARY_DIR}/
)

add_custom_command(TARGET my_custom_target_that_always_runs
  COMMENT "Run tests as post build step."
  POST_BUILD
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND ${CMAKE_COMMAND} -E env
    LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/boostbeast/lib ./unit_test
)

add_custom_target(valgrind
  COMMAND /usr/bin/valgrind
    --error-exitcode=1
    --leak-check=full
    --gen-suppressions=all
    --suppressions=${CMAKE_SOURCE_DIR}/imagex-ortho.supp
    ${CMAKE_CURRENT_BINARY_DIR}/unit_test
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
