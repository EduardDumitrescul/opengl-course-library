#pragma once

#include "fmi/Shader.h"

class Lines {
private:
	Shader* shader = nullptr;

	unsigned int vaoId;

	unsigned int verticesVboId;
	float vertices[16] = {
		-0.8f, 0.2f, 0.0f, 1.0f,
		-0.8f, 0.8f, 0.0f, 1.0f,
		-0.2f, 0.8f, 0.0f, 1.0f,
		-0.2f, 0.2f, 0.0f, 1.0f,
	};

	unsigned int colorsVboId;
	float colors[16] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
public:
	Lines(Shader* shader);

	void render();
	void cleanup();
};