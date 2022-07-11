#include <window.h>

namespace Tridme {
  Window& windowFromHandle(GLFWwindow* handle) {
    return ((Window*) glfwGetWindowUserPointer(handle))->window();
  }

  Window::Window(int w, int h, const char* t) {
    m_width = w;
    m_height = h;
    m_title = t;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(w, h, t, NULL, NULL);

    glfwSetKeyCallback(m_window, KeyCallback);

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
  }

  Window::~Window() {
    
  }

  Window& Window::window() {
    return *this;
  }

  void Window::Run() {
    while (!glfwWindowShouldClose(m_window)) {
      glClear(GL_COLOR_BUFFER_BIT);
      glfwPollEvents();
      glfwSwapBuffers(m_window);
    }
  }

  void Window::KeyCallback(GLFWwindow* handle, int key, int scancode, int action, int mods) {
    Window& window = windowFromHandle(handle);

    if (key == GLFW_KEY_E && action == GLFW_PRESS)
      LOG(INFO, "TEST");
  }
}