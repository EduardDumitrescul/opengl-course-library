#include "fmi/05-01-star/Star.h"

Star::Star()
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

void Star::update() {
	if (increase) {
		c4 += speed;
		if (c4 > 2) {
			c4 -= 2*speed;
			increase = false;
		}
	}
	else {
		c4 -= speed;
		if (c4 < 0) {
			c4 += 2 * speed;
			increase = true;
		}
	}
}

void Star::render()
{
	glBindVertexArray(vaoId);

	glPointSize(5);
	glLineWidth(10);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 12);
}

void Star::cleanup()
{
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &vboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoId);
}

float Star::getCoord4() {
	return c4;
}
