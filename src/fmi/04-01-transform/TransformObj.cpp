#include "fmi/04-01-transform/TransformObj.h"

TransformObj::TransformObj()
{
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Primele 4 valori sunt pentru pozitie (position = 0)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	// Urmatoarele 4 valori sunt pentru culoare (position = 1)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));


}

void TransformObj::update() {
	ticks++;
	int t = ticks / 80;
	if (t >= 400) {
		ticks = 0;
		t = 0;
	}

	int t1 = std::min(100, t);
	translate1 = { -0.65 * t1, -0.65 * t1 , 0 };

	if (t >= 100) {
		int t2 = std::min((t - 100), 100);
		scale = { 1 + 0.01 * t2, 1 - 0.005 * t2, 1 };
	}
	else {
		scale = { 1, 1, 1 };
	}

	if (t >= 200) {
		int t3 = std::min((t - 200), 100);
		angle = 3.14 / 4 / 100 * t3;
	}
	else {
		angle = 0;
	}

	if (t >= 300) {
		int t4 = std::min((t - 300), 100);
		translate2 = { 0.65 * t4, 0.65 * t4 , 0 };
	}
	else {
		translate2 = { 0, 0, 0 };
	}
}

void TransformObj::render()
{
	glBindVertexArray(vaoId);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void TransformObj::cleanup()
{
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoId);
}

glm::vec3 TransformObj::getTranslate1() {
	return translate1;
}

glm::vec3 TransformObj::getTranslate2() {
	return translate2;
}

glm::vec3 TransformObj::getScale() {
	return scale;
}

float TransformObj::getAngle() {
	return angle;
}
