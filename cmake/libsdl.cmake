execute_process(COMMAND ${CMAKE_COMMAND}
  -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libsdl-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libsdl-download)

add_subdirectory(${CMAKE_BINARY_DIR}/libsdl-src
  ${CMAKE_BINARY_DIR}/libsdl-build)
