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

	{
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2
		};

		VertexArray va;
		VertexBuffer vb(vertices, 3 * 3 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 3);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 3);

		Shader shader("Basic.shader");
		shader.Bind();

		va.Unbind();
		vb.Unbind();
		shader.Unbind();

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

			va.Bind();
			ib.Bind();
			shader.Bind();
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}

	glfwTerminate();
	return 0;
}