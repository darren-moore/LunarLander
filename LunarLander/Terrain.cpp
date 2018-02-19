
#include "Terrain.h"
#include <random>
#include <glm/gtc/random.hpp>


Terrain::Terrain(TerrainRenderer *renderer, glm::vec2 position, int resolution, float intensity)
		: GameObject(renderer, position), resolution(resolution), intensity(intensity), renderer(renderer){
	// Create terrain 

	generateTerrain();
	renderer->initVertexData(terrainData);

}


void Terrain::generateTerrain() {


	terrainData.resize(resolution + 1, 0.0);
	
	// We use the midpoint method for terrain generation.
	float displacement = intensity;

	// Initial edge points
	terrainData[0] = displacement*glm::linearRand(-1,1);
	terrainData[resolution] = displacement*glm::linearRand(-1, 1);
	
	displacement *= intensity;

	for (int i = 1; i < resolution; i *= 2) {
		for (int j = (resolution / i) / 2; j < resolution; j += resolution / i) {
			// Set to the average of outer pts...
			terrainData[j] = (terrainData[j - (resolution / i) / 2] + terrainData[j + (resolution / i) / 2]) / 2;

			// ...and add some random noise.
			terrainData[j] += displacement*glm::linearRand(-1, 1);
		}
		displacement *= intensity; // Refine
	}
}
