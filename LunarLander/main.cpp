#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(){

	// Init and setup GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Create GFLW window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Lunar Lander", NULL, NULL);
	if (window == NULL) {
		cout << "Error: Window creation failed" << endl;
		glfwTerminate();
		return -1;
	}

	// Init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); {
		cout << "Error: GLAD initialization failed" << endl;
		return -1;
	}


	glViewport(0, 0, 800, 600);

	// Window resize callback for dynamic viewport
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window); // double buffer!
		glfwPollEvents();
	}

	// All done.
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}