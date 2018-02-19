
#ifndef TERRAINRENDERER_H
#define TERRAINRENDERER_H

#include <glad/glad.h>
#include <vector>

#include "Renderer.h"

class TerrainRenderer : public Renderer {
public:
	TerrainRenderer(Shader &shader) : Renderer(shader), shader(shader), numVerts(0) {}
	void draw(glm::vec2 position, glm::vec2 size = glm::vec2(1.0f, 1.0f), GLfloat rotation = 0.0f);
	void initVertexData(std::vector<float> terrainData);	// Makes polygon for rendering terrain and puts in VAO;

private:
	Shader shader;
	int numVerts;

};

#endif //TERRAINRENDERER_H
