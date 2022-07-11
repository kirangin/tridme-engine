#include <Kernel/Engine.h>

namespace Tridme {
  Engine::Engine(int argc, char** argv) {
    /* Do initialize here */
    m_window = new Window(800, 600, "Tridme Engine");
  }
  
  Engine::~Engine() {
    /* Free memories */
    delete m_window;
  }

  void Engine::Start() {
    /* Do game loop */
    m_window->Run();
  }
}