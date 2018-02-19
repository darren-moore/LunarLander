
#include "TerrainRenderer.h"

using namespace glm;

void TerrainRenderer::draw(glm::vec2 position, glm::vec2 size, GLfloat rotation) {
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
	this->shader.setVec3("shaderColor", vec3(.5, .5, .5));

	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, numVerts);
	glBindVertexArray(0);
}


void TerrainRenderer::initVertexData(std::vector<float> terrainData) {
	int resolution = terrainData.size() - 1;
	numVerts = 6 * resolution;

	// 2 DOF per point * number of points per triangle* number of triangles per slice*number of slices
	GLfloat *vertices = (GLfloat*)malloc(12 * resolution * sizeof(GLfloat));
	int tri = 0;
	for (int i = 0; i < resolution; i++) {

		vertices[tri] = i / (float)resolution;
		vertices[tri + 2] = i / (float)resolution;
		vertices[tri + 4] = (i + 1) / (float)resolution;

		vertices[tri + 1] = 0;
		vertices[tri + 3] = terrainData[i];
		vertices[tri + 5] = terrainData[i + 1];

		tri += 6;
		vertices[tri] = (i) / (float)resolution;
		vertices[tri + 2] = (i + 1) / (float)resolution;
		vertices[tri + 4] = (i + 1) / (float)resolution;

		vertices[tri + 1] = 0;
		vertices[tri + 3] = terrainData[i + 1];
		vertices[tri + 5] = 0;

		tri += 6;
	}

	GLuint VBO;

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*numVerts*2, vertices, GL_STATIC_DRAW);

	glBindVertexArray(this->VAO);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	free(vertices);
}