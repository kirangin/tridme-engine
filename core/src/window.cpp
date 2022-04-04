#include <window.h>

namespace Tridme {
  Window::Window(int w, int h, const char* t) {
    m_width = w;
    m_height = h;
    m_title = t;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(w, h, t, NULL, NULL);

    if (m_window == NULL) {
      LOG(ERROR, "Cannot create GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      LOG(ERROR, "Cannot load OpenGL process!");
      Close();
      glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    event = new Event(m_window);
  }

  Window::~Window() {
    
  }

  void Window::OnEvent() {
    event->SetKeyCallback(Window::KeyCallback);
  }

  void Window::Run() {
    while (m_running) {
      OnEvent();
    }
  }

  void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)  {
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
      std::cout << "PRESSED" << std::endl;
  }
}