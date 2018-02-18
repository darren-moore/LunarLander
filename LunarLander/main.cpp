#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>

#include "stb_image.h"
#include "Shader.h"
#include "Game.h"

using namespace std;

// Window resize callback for dynamic viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint SCREEN_WIDTH = 800;
const GLuint SCREEN_HEIGHT = 600;

Game lunarLander(SCREEN_WIDTH, SCREEN_HEIGHT);

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

	glfwMakeContextCurrent(window);

	// Init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Error: GLAD initialization failed" << endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	
	// Window is now set up.
	

	//// Load image
	//int width, height, nrChannels;
	//unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

	//GLuint texture;
	//glGenTextures(1, &texture);
	//glBindTexture(GL_TEXTURE_2D, texture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//
	//if (data) {
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	//else {
	//	cout << "Error: Texture file read failed." << endl;
	//}

	//stbi_image_free(data);
	//shader.setInt("theTexture", 0);

	
	lunarLander.init();

	GLfloat dt = 0;
	GLfloat lastFrameTime = 0;

	while (!glfwWindowShouldClose(window)) {
		GLfloat currentFrameTime = glfwGetTime();
		dt = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;
		glfwPollEvents();

		lunarLander.processInput(dt);
		lunarLander.update(dt);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		lunarLander.render();

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

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS)
			lunarLander.keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			lunarLander.keys[key] = GL_FALSE;
	}

}