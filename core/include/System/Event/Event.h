#ifndef __EVENT_H__
#define __EVENT_H__

#include <glfw/include/GLFW/glfw3.h>

namespace Tridme {
  /*
   * Event class digunakan untuk mengelola interaksi yang terjadi
   * saat terdapat masukan oleh user dari perangakat keras maupun
   * perangkat lunak. Lihat (docs/event.md)
   * 
   * TODO: Implement this!
   */
  class Event {
    public: 
      Event(GLFWwindow* window);
      ~Event();

      void SetKeyCallback(GLFWkeyfun fn);
      // bool KeyDown(int key);

    private:
      GLFWwindow* m_window;

  };
}

#endif // __EVENT_H__