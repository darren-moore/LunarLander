
#include "Game.h"

using namespace std;


Game::Game(GLuint width, GLuint height) 
		: state(GAME_ACTIVE), keys(), width(width), height(height){
}
Game::~Game() {
	delete renderer;
}

void Game::init() {
	Shader shader("vertShader.vert", "fragShader.frag");
	renderer = new SpriteRenderer(shader);

	gameObjects.push_back(new Lander(renderer, glm::vec3(0.0f, 0.0f, 0.0f)));



}

void Game::addGameObject(glm::vec3 position) {
	gameObjects.push_back(new GameObject(renderer, position));

}

void Game::processInput(GLfloat const dt) {

}

void Game::update(GLfloat const dt) {
	for (auto &go : gameObjects) {
		go->update(dt, this->keys);
	}
}

void Game::render() {
	for (auto &go : gameObjects) {
		if (go->visible) {
			go->draw();
		}
	}
}