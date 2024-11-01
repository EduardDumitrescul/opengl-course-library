#pragma once

#include "fmi/Shader.h"
#include "fmi/Texture.h"

class Quadrilater {
private:
	Shader* shader = nullptr;
	Texture* texture = nullptr;

	unsigned int vaoId;

	unsigned int vboId;
	// 4 coord pozitie, 4 coord culoare, 2 coord textura
	float vertices[40] = {
		0.5f, 0.5f, 0.0f, 1.0f, 0.2f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 1.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.2f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	};

	float changeSpeed = 1e-4;
	float targetVertices[8] = {
		0.5f, 0.5,
		-0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	float random();

public:
	Quadrilater(Shader* shader, Texture* texture);
	void update();
	void render();
	void cleanup();
};