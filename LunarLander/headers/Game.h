
#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "GameObject.h"
#include "Lander.h"
#include "Terrain.h"
#include "SpriteRenderer.h"
#include "TerrainRenderer.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game {
public:
	GameState state;
	GLboolean keys[1024];	// A GLFW key table.
	GLuint width, height;

	std::vector<GameObject*> gameObjects;
	SpriteRenderer *sRenderer;
	TerrainRenderer *tRenderer;

	Game(GLuint width, GLuint height);
	~Game();

	void init();
	void addGameObject(GameObject *go);

	void update(GLfloat const dt);
	void render();

private:
	

};

#endif //GAME_H