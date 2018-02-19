
#include "Game.h"

using namespace std;


Game::Game(GLuint width, GLuint height) : state(GAME_ACTIVE), keys(), width(width), height(height){

}
Game::~Game() {
	for (auto &go : gameObjects) {
		delete go;
	}
	gameObjects.clear();

	delete sRenderer;
	delete tRenderer;
}

void Game::init() {
	Shader shader("vertShader.vert", "fragShader.frag");
	sRenderer = new SpriteRenderer(shader);
	tRenderer = new TerrainRenderer(shader);

	GameObject *lander = new Lander(sRenderer, glm::vec3(100.0f, 100.0f, 0.0f));
	GameObject *terrain = new Terrain(tRenderer, glm::vec3(0.0f, 600.0f, 0.0f), 128, .6f);
	terrain->size = glm::vec2(800.0f, 400.0f);

	addGameObject(lander);
	addGameObject(terrain);

}

void Game::addGameObject(GameObject *go) {
	gameObjects.push_back(go);
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