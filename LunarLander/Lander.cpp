
#include "Lander.h"
using namespace glm;

Lander::Lander(SpriteRenderer *renderer, glm::vec2 position)
		: GameObject(renderer, position), velocity(vec2(0.0f)), acceleration(vec2(0.0f)){

}

void Lander::update(GLfloat dt, GLboolean* keys) {

	// Integrate
	velocity += acceleration * vec2(dt);
	vec2 velocityFlipped = vec2(velocity.x, -velocity.y); // Since "up" in screenspace is smaller values
	position += velocityFlipped * vec2(dt);

	// Gravity
	acceleration = vec2(0.0f, -10.0f);

	if (keys[GLFW_KEY_W]) {
		// Must rotate thrust to be in direction of thrusters
		mat4 rotMatrix = mat4(1.0);
		rotMatrix = glm::rotate(rotMatrix, -rotation, vec3(0.0f, 0.0f, 1.0f));

		vec2 transformedThrust = rotMatrix * vec4(0.0f, 20.0f, 0.0f, 0.0f);

		// And assume mass is 1...
		acceleration.x += transformedThrust.x;
		acceleration.y += transformedThrust.y;
	}
	if (keys[GLFW_KEY_A]) {
		rotation -= dt;
	}
	if (keys[GLFW_KEY_D]) {
		rotation += dt;
	}

}