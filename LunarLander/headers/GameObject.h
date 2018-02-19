#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.h"
#include "SpriteRenderer.h"
#include "TerrainRenderer.h"


class GameObject {
public:
	glm::vec2 position;
	float rotation;
	glm::vec2 size;
	bool visible;
	GameObject(Renderer *renderer, glm::vec2 position = glm::vec2(0.0));
	Renderer *renderer;

	void draw();
	virtual void update(GLfloat dt, GLboolean* keys) {}

};

#endif //GAMEOBJECT_H