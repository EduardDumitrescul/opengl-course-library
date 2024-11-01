#include "fmi/04-01-texture/Quadrilater.h"

Quadrilater::Quadrilater(Shader* shader, Texture* texture)
{
	this->shader = shader;
	this->texture = texture;

	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Primele 4 valori dunt pentru pozitie (position = 0)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);

	// Urmatoarele 4 valori sunt pentru culoare (position = 1)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(4 * sizeof(float)));

		
	// Urmatoarele 2 valori sunt coordonatele texturii (position = 2)
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(8 * sizeof(float)));

}

void Quadrilater::render()
{
	glBindVertexArray(vaoId);
	shader->use();
	texture->use();

	glPointSize(5);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDrawArrays(GL_POINTS, 0, 4);

	shader->remove();
}

void Quadrilater::cleanup()
{
	
}
