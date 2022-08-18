#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <glad/include/glad.h>
#include <glfw/include/GLFW/glfw3.h>
#include <Utils/Logging.h>
#include <iostream>
#include <System/Event/Event.h>
#include <System/Layers/Layer.h>
#include <System/Layers/LayerStack.h>
#include <System/Layers/GUILayer.h>

namespace Tridme {  
  class Window {
    public: 
      Window(int w, int h, const char* t);
      ~Window();

      Window& window();

      inline void Close() { glfwSetWindowShouldClose(m_window, true); };
      inline GLFWwindow* GetInstance() { return m_window; }
      void Run();

      /* Event Handlers */
      static void KeyCallback(GLFWwindow* handle, int key, int scancode, int action, int mods);
      LayerStack m_layers;

    private:
      int m_width, m_height;
      const char* m_title;
      GLFWwindow* m_window;
      bool m_running = true;

      GuiLayer* m_guiLayers;

      float m_deltaTime = 0.0f;
      float m_lastFrame = 0.0f;
  };

  Window& windowFromHandle(GLFWwindow* handle);
}

#endif // __WINDOW_H__