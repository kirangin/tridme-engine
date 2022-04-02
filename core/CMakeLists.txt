include_directories(${CMAKE_SOURCE_DIR}/Core/include)
include_directories(${CMAKE_SOURCE_DIR}/vendors)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glm)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glad)
include_directories(${CMAKE_SOURCE_DIR}/vendors/stbi)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wno-int-to-pointer-cast -std=c++11 -fpic")

set_source_files_properties(src/glad.c PROPERTIES LANGUAGE CXX)

add_library(tridme SHARED 
  src/camera.cpp
  src/glad.c
  src/index_buffer.cpp
  src/mesh.cpp
  src/renderer.cpp
  src/shader.cpp
  src/texture.cpp
  src/vertex_array.cpp
  src/vertex_buffer.cpp
  src/stb_image.cpp
)

target_link_libraries(tridme -lGL -lX11 -lpthread -lXrandr -lXi -ldl)