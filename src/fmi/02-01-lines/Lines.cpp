#include "fmi/02-01-lines/Lines.h"

Lines::Lines(Shader* shader)
{
	this->shader = shader;

	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	glGenBuffers(1, &verticesVboId);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);


	glGenBuffers(1, &colorsVboId);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
}

void Lines::render()
{
	glBindVertexArray(this->vaoId);
	shader->use();
	glLineWidth(10);
	glDrawArrays(GL_LINES, 0, 4);
	shader->remove();
}

void Lines::cleanup()
{
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &verticesVboId);
	glDeleteBuffers(1, &colorsVboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoId);
}