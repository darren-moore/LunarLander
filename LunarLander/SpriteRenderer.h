#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <glad/glad.h>

#include "Renderer.h"


class SpriteRenderer : public Renderer {
public:
	SpriteRenderer(Shader &shader);

	void draw(glm::vec2 position, glm::vec2 size = glm::vec2(1, 1), GLfloat rotation = 0.0f);

private:
	Shader shader;

	void initRenderData();
};

#endif // SPRITERENDERER_H