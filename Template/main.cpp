// Codul sursa este adaptat dupa OpenGLBook.com

#include <GL/glew.h> 
#include <GL/freeglut.h> 
#include "Shader.h"

class Square
{
	GLuint vaoId, vboId, colorBufferId;
	GLfloat vertices[6 * 4] = {
		0.5f,  0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f,
		0.5f,  0.5f, 0.0f, 1.0f
	};

	GLfloat colors[6 * 4] = {
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
		1.0f, 0.5f, 0.2f, 1.0f,
	  };
	
	public:
	Square()
	{
		glGenVertexArrays(1, &vaoId);
		glBindVertexArray(vaoId);
	
		glGenBuffers(1, &vboId);
		glBindBuffer(GL_ARRAY_BUFFER, vboId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glGenBuffers(1, &colorBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void render() const
	{
		glBindVertexArray(vaoId);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 3, 3);
	}

	~Square()
	{
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &colorBufferId);
		glDeleteBuffers(1, &vboId);

		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vaoId);
	}
	
};

Shader* shader = nullptr;
Square* square = nullptr;

void RenderFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);       
	shader->use();
	square->render();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600); 
	glutCreateWindow("Grafica pe calculator - primul exemplu");
	glewInit(); 

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	shader = new Shader("example.vert", "example.frag");
	square = new Square();
	
	glutDisplayFunc(RenderFunction);
	glutMainLoop();

	delete square;
	delete shader;
}

