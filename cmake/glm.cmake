execute_process(COMMAND ${CMAKE_COMMAND}
  -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/glm-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/glm-download)

add_subdirectory(${CMAKE_BINARY_DIR}/glm-src
  ${CMAKE_BINARY_DIR}/glm-build)
