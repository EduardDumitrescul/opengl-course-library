#pragma once

#include <GL/glew.h> 

class Star {
private:
	unsigned int vaoId;

	unsigned int vboId;

	float vertices[96] = {
		0, 0, 0, 1, 1, 0, 0, 1,
		0, 100, 0, 1, 1, 1, 0, 1,
		-20, 20, 0, 1, 1, 1, 0, 1,
		-100, 20, 0, 1, 1, 1, 0, 1,
		-40, -20, 0, 1, 1, 1, 0, 1,
		-60, -100, 0, 1, 1, 1, 0, 1,
		0, -40, 0, 1, 1, 1, 0, 1,
		60, -100, 0, 1, 1, 1, 0, 1,
		40, -20, 0, 1, 1, 1, 0, 1,
		100, 20, 0, 1, 1, 1, 0, 1,
		20, 20, 0, 1, 1, 1, 0, 1,
		0, 100, 0, 1, 1, 1, 0, 1,
	};

	float c4 = 1;
	float speed = 0.0004;
	bool increase = true;

public:
	Star();
	void update();
	void render();
	void cleanup();

	float getCoord4();
};