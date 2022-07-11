#include <System/Window/Window.h>

namespace Tridme {
  Window& windowFromHandle(GLFWwindow* handle) {
    return ((Window*) glfwGetWindowUserPointer(handle))->window();
  }

  Window::Window(int w, int h, const char* t)
  : m_width(w),
    m_height(h),
    m_title(t) {
    /* Initialize GLFW */
    glfwInit();

    /* Set Window Hint */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    /* Create Window */
    m_window = glfwCreateWindow(w, h, t, NULL, NULL);

    if (m_window == NULL) {
      LOG(ERROR, "Cannot create GLFW window");
      exit(1);
    }

    /* Register Event Handlers */
    glfwSetKeyCallback(m_window, KeyCallback);

    /* Create an OpenGL context */
    glfwMakeContextCurrent(m_window);

    /* Load OpenGL functions */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      LOG(ERROR, "Cannot load OpenGL process!");
      Close();
      glfwTerminate();
    }

    m_guiLayers = new GuiLayer();
    m_layers.PushOverlay(m_guiLayers);

    /**
     * Apply layers
     */
    for (Layer* layer : m_layers) {
      layer->OnAttach();
    }

    m_guiLayers->OnAttach(m_window);
  }

  Window::~Window() {
    delete m_title;
  
    for (Layer* layer : m_layers) {
      layer->OnDetach();
    }

    m_guiLayers->OnAttach(m_window);
  }

  Window& Window::window() {
    return *this;
  }

  void Window::Run() {
    while (!glfwWindowShouldClose(m_window)) {
      /* Delta Time */
      float currentFrame = glfwGetTime();
      m_deltaTime = currentFrame - m_lastFrame;
      m_lastFrame = currentFrame;
      
      glClear(GL_COLOR_BUFFER_BIT);
      glfwPollEvents();

      for (Layer* layer : m_layers) {
        layer->OnUpdate(m_deltaTime);
      }

      m_guiLayers->ImGuiBegin();
      // for (Layer* layer : m_layers) {
      //   layer->OnImGuiRender();
      // }
      m_guiLayers->ImGuiRender();
      m_guiLayers->ImGuiEnd();

      glfwSwapBuffers(m_window);
    }
  }

  void Window::KeyCallback(GLFWwindow* handle, int key, int scancode, int action, int mods) {
    Window& window = windowFromHandle(handle);

    if (key == GLFW_KEY_E && action == GLFW_PRESS)
      LOG(INFO, "TEST");
  }
}