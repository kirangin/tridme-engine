#include <event.h>

namespace Tridme {
  Event::Event(GLFWwindow* window) {
    m_window = window;
  }

  Event::~Event() {
    
  }

  void Event::SetKeyCallback(GLFWkeyfun fn) {
    glfwSetKeyCallback(m_window, fn);
  }
}