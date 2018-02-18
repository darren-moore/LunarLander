#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <glad/glad.h>

#include "Shader.h"


class SpriteRenderer {
public:
	SpriteRenderer(Shader &shader);

	void drawSprite(glm::vec2 position, glm::vec2 size = glm::vec2(1, 1), GLfloat rotation = 0.0f);

private:
	Shader shader;
	GLuint quadVAO;

	void initRenderData();
};

#endif // SPRITERENDERER_H