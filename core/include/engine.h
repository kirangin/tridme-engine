#ifndef ENGINE_H
#define ENGINE_H

#include <vertex_buffer.h>
#include <vertex_buffer_layout.h>
#include <index_buffer.h>
#include <vertex_array.h>
#include <shader.h>
#include <texture.h>
#include <mesh.h>
#include <camera.h>
#include <window.h>

namespace Tridme {
  class Engine {
    public: 
      Engine(int argc, char** argv);
      ~Engine();

      void Start();

    private:
      Window* m_window;
  }; 
}

#endif