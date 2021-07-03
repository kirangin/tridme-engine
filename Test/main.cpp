#include <engine.h>
#include <logging.h>
#include <extern/GLFW/glfw3.h>

int main(int argc, char* argv[]) {
	if (!glfwInit()) { LOG(ERROR, "Cannot Initialize GLFW!"); }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Tridme Engine", NULL, NULL);

	if (!window) {
		LOG(ERROR, "Cannot create GLFW window!");
		return -1;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG(ERROR, "Cannot load OpenGL process!");
		return -1;
		glfwTerminate();
	}

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}