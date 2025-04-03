#pragma once

#include <GL/glew.h> 
#include "glm/gtc/type_ptr.hpp"
#include <algorithm>

class TransformObj {
private:
	unsigned int vaoId;

	unsigned int vboId;
	float vertices[32] = {
		50, 50, 0, 1, 1.0f, 0.5f, 0.2f, 1.0f,
		80, 50, 0, 1, 1.0f, 0.5f, 0.2f, 1.0f,
		50, 80, 0, 1, 1.0f, 0.5f, 0.2f, 1.0f,
		80, 80, 0, 1, 1.0f, 0.5f, 0.2f, 1.0f,
	};

	int ticks = 0;
	glm::vec3 translate1 = { 0, 0, 0 };
	glm::vec3 scale = { 1, 1, 1 };
	float angle = 0;
	glm::vec3 translate2 = { 0, 0, 0 };

public:
	TransformObj();

	void update();
	void render();
	void cleanup();

	glm::vec3 getTranslate1();
	glm::vec3 getScale();
	float getAngle();
	glm::vec3 getTranslate2();
};