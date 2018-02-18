#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "GameObject.h"
#include "Lander.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game {
public:
	GameState state;
	GLboolean keys[1024];
	GLuint width, height;
	std::vector<GameObject*> gameObjects;
	SpriteRenderer *renderer;

	Game(GLuint width, GLuint height);
	~Game();

	void init();
	void addGameObject(glm::vec3 position);

	void processInput(GLfloat const dt);
	void update(GLfloat const dt);
	void render();

private:
	

};

#endif //GAME_H