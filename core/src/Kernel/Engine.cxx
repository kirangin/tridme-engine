#include <Kernel/Engine.h>

namespace Tridme {
  Engine::Engine(int argc, char** argv) {
    /* Do initialize here */
  }
  
  Engine::~Engine() {
    /* Free memories */
    delete m_window;
  }

  void Engine::Start() {
    /* Do game loop */
    m_window = new Window(800, 600, "Tridme Engine");
    m_window->Run();
  }

  void Engine::Start(Window& window) {
    /* Do game loop */
    m_window = &window;
    m_window->Run();
  }
}