#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <glad/include/glad.h>
#include <glfw/include/GLFW/glfw3.h>
#include <logging.h>
#include <iostream>

namespace Tridme {
  class Window {
    public: 
      Window(int w, int h, const char* t);
      ~Window();

      inline void Close() { glfwSetWindowShouldClose(m_window, true); };
      
      void OnRender();
      void OnEvent();

      void TRIDME_KEY_CALLBACK(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:
      int m_width, m_height;
      const char* m_title;
      GLFWwindow* m_window;
      bool m_running = true;
  };
}

#endif // __WINDOW_H__