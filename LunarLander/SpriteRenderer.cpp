
#include "SpriteRenderer.h"

using namespace glm;

SpriteRenderer::SpriteRenderer(Shader &shader) : Renderer(shader), shader(shader){
	initRenderData();

}

void SpriteRenderer::draw(glm::vec2 position, glm::vec2 size, GLfloat rotation) {
	this->shader.use();
	mat4 model = mat4(1.0);

	model = translate(model, vec3(position, 0.0f));

	// Rotate about centre.
	model = translate(model, vec3(vec2(0.5*size.x, 0.5*size.y), 0.0f));
	model = rotate(model, rotation, vec3(0.0f, 0.0f, 1.0f));
	model = translate(model, vec3(vec2(-0.5*size.x, -0.5*size.y), 0.0f));

	model = scale(model, vec3(size, 1.0f));

	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
	this->shader.setMat4("projection", projection);
	this->shader.setMat4("model", model);
	this->shader.setVec3("shaderColor", vec3(.3, .2, .5));

	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}


void SpriteRenderer::initRenderData() {
	GLuint VBO;
	//GLfloat vertices[] = {
	//	// Pos      // Tex
	//	0.0f, 1.0f, 0.0f, 1.0f,
	//	1.0f, 0.0f, 1.0f, 0.0f,
	//	0.0f, 0.0f, 0.0f, 0.0f,

	//	0.0f, 1.0f, 0.0f, 1.0f,
	//	1.0f, 1.0f, 1.0f, 1.0f,
	//	1.0f, 0.0f, 1.0f, 0.0f
	//};

	GLfloat vertices[] = {
		// Pos  
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
	};

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindVertexArray(this->VAO);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
