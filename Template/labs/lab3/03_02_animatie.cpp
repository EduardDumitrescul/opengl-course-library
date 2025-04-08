// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul III - 03_02_animatie.cpp |
// // ============================================
// //
// //	Program ce deseneaza un dreptunghi ce se deplaseaza stanga-dreapta si are un patrat ce orbiteaza
// //	in jurul sau, folosindu-se tehnicile MODERN OpenGL.
// //	ELEMENTE DE NOUTATE:
// //	- utilizeaza diverse transformari si compunerea acestora folosind biblioteca glm,
// //	- functii pentru utilizarea mouse-ului;
// //
//
// #include <GL/glew.h> 
// #include <GL/freeglut.h> 
// #include "Shader.h"
// #include "glm/ext/matrix_clip_space.hpp"
// #include "glm/gtx/transform.hpp"
//
// float xMin = -450.f, xMax = 450.f, yMin = -300.f, yMax = 300.f;
//
// class Axis
// {
// 	GLuint vaoId, vboId, colorBufferId;
// 	GLfloat vertices[4 * 4] = {
// 		-450.0f, 0.0f, 0.0f, 1.0f,
// 		450.0f,  0.0f, 0.0f, 1.0f,
// 		0.0f, -300.0f, 0.0f, 1.0f,
// 		0.0f, 300.0f, 0.0f, 1.0f,
// 	};
//
// 	GLfloat colors[4 * 4] = {
// 		1.0f, 0.0f, 0.0f, 1.0f,
// 		0.0f, 1.0f, 0.0f, 1.0f,
// 		0.0f, 0.0f, 1.0f, 1.0f,
// 		1.0f, 0.0f, 0.0f, 1.0f,
// 	  };
// 	
// 	public:
// 	Axis()
// 	{
// 		glGenVertexArrays(1, &vaoId);
// 		glBindVertexArray(vaoId);
// 	
// 		glGenBuffers(1, &vboId);
// 		glBindBuffer(GL_ARRAY_BUFFER, vboId);
// 		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
// 		glEnableVertexAttribArray(0);
// 		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
//
// 		glGenBuffers(1, &colorBufferId);
// 		glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);
// 		glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
//
// 		glEnableVertexAttribArray(1);
// 		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
// 	}
//
// 	void render(const Shader* shader) const
// 	{
// 		glBindVertexArray(vaoId);
// 		
// 		shader->setMat4("modelMatrix", glm::mat4(1.0f));
// 		shader->setInt("colorCode", 0);
// 		glDrawArrays(GL_LINES, 0, 4);
// 	}
//
// 	~Axis()
// 	{
// 		glDisableVertexAttribArray(1);
// 		glDisableVertexAttribArray(0);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &colorBufferId);
// 		glDeleteBuffers(1, &vboId);
//
// 		glBindVertexArray(0);
// 		glDeleteVertexArrays(1, &vaoId);
// 	}
// 	
// };
//
// class DreptunghiCuSatelit
// {
// 	GLuint vaoId, vboId;
// 	GLfloat vertices[4 * 4] = {
// 		-50.0f,  -50.0f, 0.0f, 1.0f,
// 		50.0f, -50.0f, 0.0f, 1.0f,
// 		50.0f,  50.0f, 0.0f, 1.0f,
// 		-50.0f,  50.0f, 0.0f, 1.0f,
// 	};
//
// 	float xPosition = 0.0, direction = 0.0, positionStep=0.3, angleStep = 0.0002, angle = 0;
// 	
// public:
// 	DreptunghiCuSatelit()
// 	{
// 		glGenVertexArrays(1, &vaoId);
// 		glBindVertexArray(vaoId);
// 	
// 		glGenBuffers(1, &vboId);
// 		glBindBuffer(GL_ARRAY_BUFFER, vboId);
// 		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
// 		glEnableVertexAttribArray(0);
// 		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
// 	}
//
// 	void render(const Shader* shader) const
// 	{
// 		glBindVertexArray(vaoId);
//
// 		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xPosition, 0.0, 0.0));
// 		glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(1.1, 0.3, 0.0));
//
// 		glm::mat4 modelMatrix = translationMatrix * scaleMatrix;
// 		shader->setMat4("modelMatrix", modelMatrix);
// 		shader->setInt("colorCode", 1);
// 		glDrawArrays(GL_POLYGON, 0, 4);
//
// 		
// 		glm::mat4 scaleMatrix2 =  glm::scale(glm::mat4(1.0f), glm::vec3(0.25, 0.25, 0.0));
// 		glm::mat4 relativeTranslationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 80.0, 0.0));
// 		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1));
// 		modelMatrix = translationMatrix * rotationMatrix * relativeTranslationMatrix * scaleMatrix2;
// 		shader->setMat4("modelMatrix", modelMatrix);
// 		shader->setInt("colorCode", 2);
// 		glDrawArrays(GL_POLYGON, 0, 4);
// 	}
//
// 	void update()
// 	{
// 		xPosition += direction;
// 		angle += angleStep;
// 		if (xPosition < xMin + 50)
// 		{
// 			goRight();
// 		}
// 		else if (xPosition > xMax - 50)
// 		{
// 			goLeft();
// 		}
// 	}
//
// 	void goLeft()
// 	{
// 		direction = -positionStep;
// 	}
//
// 	void goRight()
// 	{
// 		direction = positionStep;
// 	}
//
// 	~DreptunghiCuSatelit()
// 	{
// 		glDisableVertexAttribArray(0);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &vboId);
//
// 		glBindVertexArray(0);
// 		glDeleteVertexArrays(1, &vaoId);
// 	}
// 	
// };
//
// Shader* shader = nullptr;
// Axis* axis = nullptr;
// DreptunghiCuSatelit* dreptunghiCuSatelit = nullptr;
//
// void RenderFunction()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	shader->use();
// 	
// 	glm::mat4 projectionMatrix = glm::ortho(xMin, xMax, yMin, yMax);
// 	shader->setMat4("projectionMatrix", projectionMatrix);
// 	
// 	axis->render(shader);
// 	dreptunghiCuSatelit->render(shader);
// 	
// 	glutSwapBuffers();
// 	glFlush();
// }
//
// void MouseFunction(int button, int state, int x, int y)
// {
// 	switch (button) {
// 	case GLUT_LEFT_BUTTON:			
// 		if (state == GLUT_DOWN)
// 			dreptunghiCuSatelit->goLeft();
// 		break;
// 	case GLUT_RIGHT_BUTTON:			
// 		if (state == GLUT_DOWN)
// 			dreptunghiCuSatelit->goRight();
// 		break;
// 	default:
// 		break;
// 	}
// }
//
// void IdleFunction() {
// 	dreptunghiCuSatelit->update();
// 	glutPostRedisplay();
// }
//
//
// int main(int argc, char* argv[])
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
// 	glutInitWindowPosition(100, 100);
// 	glutInitWindowSize(600, 600); 
// 	glutCreateWindow("Dreptunghi cu satelit - OpenGL <<nou>>");
// 	glewInit(); 
//
// 	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
// 	shader = new Shader("03_02_Shader.vert", "03_02_Shader.frag");
// 	axis = new Axis();
// 	dreptunghiCuSatelit = new DreptunghiCuSatelit();
// 	
// 	glutDisplayFunc(RenderFunction);
// 	glutMouseFunc(MouseFunction);
// 	glutIdleFunc(IdleFunction);
// 	glutMainLoop();
//
// 	delete axis;
// 	delete dreptunghiCuSatelit;
// 	delete shader;
// }
//
