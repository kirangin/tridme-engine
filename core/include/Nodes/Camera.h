#ifndef CAMERA_H
#define CAMERA_H

#include <Kernel/Core.h>

namespace Tridme {
  class Camera {
    public:
      Camera(GLfloat width, GLfloat height, GLfloat nearPlane, GLfloat farPlane, glm::vec3 camPos);
      ~Camera();

      glm::mat4 getViewMatrix();
      glm::mat4 getProjectionMatrix();
      glm::vec3 getCameraPosition();

      void SetPosition(glm::vec3 new_pos);

      /* Camera settings */
      float speed;
      float sensitivity;
      float zoom;
      float yaw;
      float pitch;
      float near;
      float far;

      glm::vec3 m_cameraFront;
      glm::vec3 m_cameraUp;
      glm::vec3 m_cameraRight;

      /* Movements */
      void Move(GLFWwindow* window, float dt);
      void EulerAngle(double xpos, double ypos);
    
    private:
      glm::mat4 m_viewMatrix;
      glm::mat4 m_projectionMatrix;
      glm::vec3 m_cameraPosition;

      float m_width;
      float m_height;
      float m_last_x;
      float m_last_y;
      float m_first_mouse;

      void Update();
  };
}

#endif