
#include "GameObject.h"

using namespace glm;

GameObject::GameObject(SpriteRenderer *renderer, glm::vec2 position)
		: position(position), spriteRenderer(renderer), visible(true), size(vec2(1.0)), rotation(glm::radians(0.0f)),
		destroyOnNextFrame(false){

}


void GameObject::draw() {
	spriteRenderer->drawSprite(position, size, rotation);
}
