#include <engine.h>
#include <logging.h>
#include <extern/GLFW/glfw3.h>

Camera* camera;
Renderer* render;

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

	{
		glEnable(GL_DEPTH_TEST);

		Shader* shader = new Shader("Basic.shader");
		camera = new Camera(45.0f, 800, 600, 0.1f, 1000.0f, 
                      glm::vec3(0.0f, 0.0f, -6.0f));
		render = new Renderer(MESH_TYPE::MESH_CUBE, camera); 
		render->SetPosition(glm::vec3(0.0f));
		render->SetShader(shader);
		render->SetColor(glm::vec3(1.0f, 1.0f, 0.0f));

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

			render->DrawMesh();

			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}

	glfwTerminate();
	return 0;
}