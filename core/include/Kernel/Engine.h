#ifndef ENGINE_H
#define ENGINE_H

#include <System/Renderer/VertexBuffer.h>
#include <System/Renderer/VertexBufferLayout.h>
#include <System/Renderer/IndexBuffer.h>
#include <System/Renderer/VertexArray.h>
#include <System/Renderer/Shader.h>
#include <System/Renderer/Texture.h>
#include <System/Renderer/Mesh.h>
#include <Nodes/Camera.h>
#include <System/Window/Window.h>
#include <System/Layers/Layer.h>
#include <System/Layers/LayerStack.h>

namespace Tridme {
  class Engine {
    public: 
      Engine(int argc, char** argv);
      ~Engine();

      void Start();
      void Start(Window& window);

    private:
      Window* m_window;
  }; 
}

#endif