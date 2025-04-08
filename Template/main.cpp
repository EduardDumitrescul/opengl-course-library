//
// ================================================
// | Grafica pe calculator                        |
// ================================================
// | Laboratorul III - 03_05_keyboard.cpp |
// ======================================
//
//	Realizarea unei scene 2D in care obiectele se misca, folosindu-se tehnicile MODERN OpenGL;
//	ELEMENTE DE NOUTATE:
//	- functii pentru tastatura;

#include <GL/glew.h> 
#include <GL/freeglut.h> 
#include "Shader.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtx/transform.hpp"

float xMin = -400.f, xMax = 400.f, yMin = -300.f, yMax = 300.f;

class Axis
{
	GLuint vaoId, vboId, colorBufferId;
	GLfloat vertices[4 * 4] = {
		-400.0f, 0.0f, 0.0f, 1.0f,
		400.0f,  0.0f, 0.0f, 1.0f,
		0.0f, -300.0f, 0.0f, 1.0f,
		0.0f, 300.0f, 0.0f, 1.0f,
	};

	GLfloat colors[4 * 4] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
	};
	
	public:
	Axis()
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

	void render(const Shader* shader) const
	{
		glBindVertexArray(vaoId);
		
		shader->setMat4("modelMatrix", glm::mat4(1.0f));
		shader->setInt("colorCode", 0);
		
		glLineWidth(1.0);
		glDrawArrays(GL_LINES, 0, 4);
	}

	~Axis()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vboId);
		glDeleteBuffers(1, &colorBufferId);
		
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vaoId);
	}
};

class PuncteInColturi
{
	GLuint vaoId, vboId, colorBufferId;
	
	GLfloat vertices[4 * 4] = {
		-390.0f, -290.0f, 0.0f, 1.0f,
		390.0f,  -290.0f, 0.0f, 1.0f,
		390.0f, 290.0f, 0.0f, 1.0f,
		-390.0f, 290.0f, 0.0f, 1.0f,
	};

	GLfloat colors[4 * 4] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.1f, 1.0f,
	};
	
public:
	PuncteInColturi()
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

	void render(const Shader* shader) const
	{
		glBindVertexArray(vaoId);
		
		shader->setMat4("modelMatrix", glm::mat4(1.0f));
		shader->setInt("colorCode", 0);
		glPointSize(15.0f);
		glEnable(GL_POINT_SMOOTH);
		glDrawArrays(GL_POINTS, 0, 4);
	}

	~PuncteInColturi()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &colorBufferId);
		glDeleteBuffers(1, &vboId);
		
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vaoId);
	}
};

class Dreptunghi
{
	GLuint vaoId, vboId;
	GLfloat vertices[5 * 4] = {
		-50.0f,  -50.0f, 0.0f, 1.0f,
		50.0f, -50.0f, 0.0f, 1.0f,
		50.0f,  50.0f, 0.0f, 1.0f,
		-50.0f,  50.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f // originea
	};

	
	float xPosition = 0.0, yPosition = 0.0;
	float angle = 0.0;
	
public:
	Dreptunghi()
	{
		glGenVertexArrays(1, &vaoId);
		glBindVertexArray(vaoId);
	
		glGenBuffers(1, &vboId);
		glBindBuffer(GL_ARRAY_BUFFER, vboId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void render(const Shader* shader) const
	{
		glBindVertexArray(vaoId);
		glPointSize(15.0f);
		glEnable(GL_POINT_SMOOTH);

		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xPosition, yPosition, 0.0));
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 modelMatrix = translationMatrix * rotationMatrix;
		
		shader->setMat4("modelMatrix", modelMatrix);
		shader->setInt("colorCode", 1);
		glDrawArrays(GL_POLYGON, 0, 4);

		shader->setInt("colorCode", 2);
		glDrawArrays(GL_POINTS, 4, 1);
	}

	void rotate(float deltaAngle)
	{
		angle += deltaAngle;
	}

	void move(float dx, float dy)
	{
		xPosition += dx;
		yPosition += dy;
	}

	~Dreptunghi()
	{
		glDisableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vboId);
		
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &vaoId);
	}
};

Shader* shader = nullptr;
Axis* axis = nullptr;
Dreptunghi* dreptunghi = nullptr;
PuncteInColturi* puncteInColturi = nullptr;

void ProcessNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'l':
		dreptunghi->rotate(0.2);
		break;
	case 'r':
		dreptunghi->rotate(-0.2);
		break;
	}
	if (key == 27)
		exit(0);
}

void ProcessSpecialKeys(int key, int x, int y) 
{
	switch (key)			
	{						
		case GLUT_KEY_LEFT:
			dreptunghi->move(-10, 0);
			break;
		case GLUT_KEY_RIGHT:
			dreptunghi->move(10, 0);
			break;
		case GLUT_KEY_UP:
			dreptunghi->move(0, 10);
			break;
		case GLUT_KEY_DOWN:
			dreptunghi->move(0, -10);
			break;
	}
}



void RenderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(15.0f);
	shader->use();
	
	glm::mat4 projectionMatrix = glm::ortho(xMin, xMax, yMin, yMax);
	shader->setMat4("projectionMatrix", projectionMatrix);
	
	axis->render(shader);
	dreptunghi->render(shader);
	puncteInColturi->render(shader);
	
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600); 
	glutCreateWindow("Rotirea unui patrat in jurul centrului sau - OpenGL <<nou>>");
	glewInit(); 

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	shader = new Shader("03_05_Shader.vert", "03_05_Shader.frag");
	axis = new Axis();
	dreptunghi = new Dreptunghi();
	puncteInColturi = new PuncteInColturi();
	
	glutDisplayFunc(RenderFunction);
	glutIdleFunc(RenderFunction);		
	glutKeyboardFunc(ProcessNormalKeys);
	glutSpecialFunc(ProcessSpecialKeys);
	glutMainLoop();

	delete axis;
	delete shader;
	delete dreptunghi;
}

