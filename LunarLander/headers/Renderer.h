
#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>

#include "Shader.h"

class Renderer {
public:
	Renderer(Shader &shader) : shader(shader) { }

	virtual void draw(glm::vec2 position, glm::vec2 size = glm::vec2(1, 1), GLfloat rotation = 0.0f) {}

protected:
	GLuint VAO;
	Shader shader;

};



#endif // RENDERER_H