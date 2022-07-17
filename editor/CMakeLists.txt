include_directories(${CMAKE_SOURCE_DIR}/core/include)
include_directories(${CMAKE_SOURCE_DIR}/editor/include)
include_directories(${CMAKE_SOURCE_DIR}/vendors)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glm)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glad)
include_directories(${CMAKE_SOURCE_DIR}/vendors/stbi)

add_executable (
  editor 
  src/Entry/Main.cxx
  src/GUI/Layer.cxx
)

target_link_libraries(editor tridme imgui glfw OpenGL::GL)
find_package(OpenGL REQUIRED)