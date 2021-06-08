#ifndef CAMERA_H
#define CAMERA_H

#include <core.h>

class Camera {
	public:
		Camera(GLfloat FOV, GLfloat width, GLfloat height, GLfloat nearPlane, GLfloat farPlane, glm::vec3 camPos);
		~Camera();

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();
		glm::vec3 getCameraPosition();

	private:
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		glm::vec3 cameraPosition;
};

#endif