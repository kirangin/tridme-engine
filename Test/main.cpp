#include <engine.h>
#include <logging.h>
#include <extern/GLFW/glfw3.h>

int main(int argc, char* argv[]) {
	if (!glfwInit()) { LOG(ERROR, "Cannot Initialize GLFW!"); }

	return 0;
}