#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

#include "GameObject.h"

class Terrain : public GameObject {
public:
	Terrain(TerrainRenderer *renderer, glm::vec2 position = glm::vec2(0.0), int resolution = 128, float intensity = .6f);
	void generateTerrain();
	TerrainRenderer *renderer;

private:
	std::vector<float> terrainData;
	int resolution; // Should be of the form 2^n
	float intensity;
	

};

#endif // TERRAIN_H