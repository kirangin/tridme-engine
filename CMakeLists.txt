cmake_minimum_required(VERSION 3.16.3)

project(Tridme VERSION 1.0
        DESCRIPTION "Game Engine"
        LANGUAGES CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(vendors/glfw)
add_subdirectory(vendors/imgui)
add_subdirectory(Core)
add_subdirectory(sandbox)

file(GLOB SHADERS
  "sandbox/*.shader"
)
file(COPY ${SHADERS} DESTINATION ${CMAKE_BINARY_DIR}/bin)