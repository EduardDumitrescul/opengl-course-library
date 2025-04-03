#include "fmi/02-01-lines/LineStrip.h"

LineStrip::LineStrip()
{
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

void LineStrip::render()
{
	glBindVertexArray(this->vaoId);
	glLineWidth(10);
	glDrawArrays(GL_LINE_STRIP, 0, 4);
}

void LineStrip::cleanup()
{
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &verticesVboId);
	glDeleteBuffers(1, &colorsVboId);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &vaoId);
}