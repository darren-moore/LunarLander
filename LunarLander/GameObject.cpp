
#include "GameObject.h"

using namespace glm;

GameObject::GameObject(Renderer *renderer, glm::vec2 position)
		: position(position), renderer(renderer), visible(true), size(vec2(100.0)), rotation(glm::radians(0.0f)){

}


void GameObject::draw() {
	renderer->draw(position, size, rotation);
}
