include_directories(${CMAKE_SOURCE_DIR}/core/include)
include_directories(${CMAKE_SOURCE_DIR}/vendors)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glm)
include_directories(${CMAKE_SOURCE_DIR}/vendors/glad)
include_directories(${CMAKE_SOURCE_DIR}/vendors/stbi)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wno-int-to-pointer-cast -std=c++11 -fpic")
set_source_files_properties(System/OpenGL/glad.c PROPERTIES LANGUAGE CXX)

set (
  SRC_CORE
  Kernel/Engine.cxx
  Nodes/Camera.cxx
  System/Event/Event.cxx 
  System/Layers/Layer.cxx
  System/Layers/LayerStack.cxx
  System/Layers/GUILayer.cxx
  System/OpenGL/glad.c
  System/Renderer/IndexBuffer.cxx
  System/Renderer/Mesh.cxx
  System/Renderer/MeshRenderer.cxx
  System/Renderer/Renderer.cxx
  System/Renderer/Shader.cxx
  System/Renderer/StbImage.cxx
  System/Renderer/Texture.cxx
  System/Renderer/VertexArray.cxx
  System/Renderer/VertexBuffer.cxx
  System/Window/Window.cxx
  Utils/Logging.cxx
)

add_library (
  tridme SHARED ${SRC_CORE}
)

target_link_libraries(tridme -lGL -lX11 -lpthread -lXrandr -lXi -ldl)