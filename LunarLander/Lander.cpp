
#include "Lander.h"
using namespace glm;

Lander::Lander(SpriteRenderer *renderer, glm::vec2 position)
		: GameObject(renderer, position), velocity(vec2(0.0f)), acceleration(vec2(0.0f)){

}

void Lander::update(GLfloat dt, GLboolean* keys) {


	velocity += acceleration * vec2(dt);
	position += velocity * vec2(dt);

	acceleration = vec2(0.0f, 0.5f);

	if (keys[GLFW_KEY_W]) {
		mat4 rotMatrix = mat4(1.0);
		rotMatrix = glm::rotate(rotMatrix, rotation, vec3(0.0f, 0.0f, 1.0f));
		vec2 transformedAccel = rotMatrix * vec4(0.0f, 1.0f, 0.0f, 0.0f);
		acceleration.x -= transformedAccel.x;
		acceleration.y -= transformedAccel.y;
	}
	if (keys[GLFW_KEY_A]) {
		rotation -= dt;
	}
	if (keys[GLFW_KEY_D]) {
		rotation += dt;
	}

}