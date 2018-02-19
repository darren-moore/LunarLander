#ifndef LANDER_H
#define LANDER_H

#include "GameObject.h"

class Lander : public GameObject {
public:
	Lander(SpriteRenderer *renderer, glm::vec2 position = glm::vec2(0.0));
	glm::vec2 velocity;
	glm::vec2 acceleration;

	void update(GLfloat dt, GLboolean* keys);

};

#endif // LANDER_H