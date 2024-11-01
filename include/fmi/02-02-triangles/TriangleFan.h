#pragma once

#include "fmi/Shader.h"

class TriangleFan {
private:
	Shader* shader = nullptr;

	unsigned int vaoId;

	unsigned int verticesVboId;
	float vertices[24] = {
		-0.6f, -0.8f, 0.0f, 1.0f,
		-0.2f, -0.8f, 0.0f, 1.0f,
		-0.4f, -0.6f, 0.0f, 1.0f,
		-0.4f, -0.4f, 0.0f, 1.0f,
		-0.6f, -0.6f, 0.0f, 1.0f,
		-0.8f, -0.4f, 0.0f, 1.0f,

	};

	unsigned int colorsVboId;
	float colors[24] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};
public:
	TriangleFan(Shader* shader);

	void render();
	void cleanup();
};