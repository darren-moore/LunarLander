#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>

using namespace std;

// Window resize callback for dynamic viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


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
	
	// Window is now set up.

	// Compile and link shaders
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	int  shaderSuccess;
	char shaderInfoLog[512];
	{
		// Vertex shader
		const char* vertexShaderSource;
		std::fstream vfile("vertShader.vert");
		std::stringstream vbuffer;
		vbuffer << vfile.rdbuf();
		string vString = vbuffer.str();
		vertexShaderSource = vString.c_str();
		vfile.close();
		
		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// Check for shader compilation errors
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderSuccess);
		if (!shaderSuccess) {
			glGetShaderInfoLog(vertexShader, 512, NULL, shaderInfoLog);
			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << shaderInfoLog << endl;
		}


		// Fragment shader
		const char* fragmentShaderSource;
		std::ifstream ffile("fragShader.frag");
		std::stringstream fbuffer;
		fbuffer << ffile.rdbuf();
		string fString = fbuffer.str();
		fragmentShaderSource = fString.c_str();
		ffile.close();

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		// Check for shader compilation errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &shaderSuccess);
		if (!shaderSuccess) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, shaderInfoLog);
			cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << shaderInfoLog << endl;
		}

		// Attach shaders to shader program
		
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// Check for shader linking errors
		glGetShaderiv(shaderProgram, GL_LINK_STATUS, &shaderSuccess);
		if (!shaderSuccess) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, shaderInfoLog);
			cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << shaderInfoLog << endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	// Vertex array object
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Vertex buffer object
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

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

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

}