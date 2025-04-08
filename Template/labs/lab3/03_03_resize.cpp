// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul III - 03_03_resize.cpp |
// // ======================================
// //
// //	Program care arata modalitati de utilizare ale proiectiei ortogonale. Se vor desena un patrat si un sistem de axe, folosindu-se tehnicile MODERN OpenGL;
// //	ELEMENTE DE NOUTATE:
// //	- pentru a stabili o fereastra de "decupare" intr-o scena 2D putem folosi atat functia glm::ortho, cat si indicarea explicita a transformarilor;
// //
//
// #include <GL/glew.h> 
// #include <GL/freeglut.h> 
// #include "Shader.h"
// #include "glm/ext/matrix_clip_space.hpp"
// #include "glm/gtx/transform.hpp"
//
// float xMin = -400, xMax = 500, yMin = -200, yMax = 400;
// float sceneWidth = xMax - xMin, sceneHeight = yMax - yMin;
// float xSceneCenter = (xMin + xMax) * 0.5, ySceneCenter = (yMin + yMax) * 0.5;
//
// class Axis
// {
// 	GLuint vaoId, vboId;
// 	GLfloat vertices[4 * 4] = {
// 		-400.0f, 0.0f, 0.0f, 1.0f,
// 		500.0f,  0.0f, 0.0f, 1.0f,
// 		0.0f, -200.0f, 0.0f, 1.0f,
// 		0.0f, 400.0f, 0.0f, 1.0f,
// 	};
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
// 	}
//
// 	void render(const Shader* shader) const
// 	{
// 		glBindVertexArray(vaoId);
// 		
// 		shader->setMat4("modelMatrix", glm::mat4(1.0f));
// 		shader->setInt("colorCode", 1);
// 		glDrawArrays(GL_LINES, 0, 4);
// 	}
//
// 	~Axis()
// 	{
// 		glDisableVertexAttribArray(0);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &vboId);
// 		
// 		glBindVertexArray(0);
// 		glDeleteVertexArrays(1, &vaoId);
// 	}
// };
//
// class PuncteInColturi
// {
// 	GLuint vaoId, vboId, colorBufferId;
// 	GLfloat vertices[4 * 4] = {
// 		-390.0f, -190.0f, 0.0f, 1.0f,
// 		490.0f,  -190.0f, 0.0f, 1.0f,
// 		490.0f, 390.0f, 0.0f, 1.0f,
// 		-390.0f, 390.0f, 0.0f, 1.0f,
// 	};
//
// 	GLfloat colors[4 * 4] = {
// 		1.0f, 0.0f, 0.0f, 1.0f,
// 		0.0f, 1.0f, 0.0f, 1.0f,
// 		0.0f, 0.0f, 1.0f, 1.0f,
// 		0.8f, 0.4f, 0.0f, 1.0f,
// 	};
// 	
// public:
// 	PuncteInColturi()
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
// 		glPointSize(15.0f);
// 		glEnable(GL_POINT_SMOOTH);
// 		glDrawArrays(GL_POINTS, 0, 4);
// 	}
//
// 	~PuncteInColturi()
// 	{
// 		glDisableVertexAttribArray(0);
// 		glDisableVertexAttribArray(1);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &colorBufferId);
// 		glDeleteBuffers(1, &vboId);
// 		
// 		glBindVertexArray(0);
// 		glDeleteVertexArrays(1, &vaoId);
// 	}
// };
//
// class Dreptunghi
// {
// 	GLuint vaoId, vboId;
// 	GLfloat vertices[4 * 4] = {
// 		-50.0f,  -50.0f, 0.0f, 1.0f,
// 		50.0f, -50.0f, 0.0f, 1.0f,
// 		50.0f,  50.0f, 0.0f, 1.0f,
// 		-50.0f,  50.0f, 0.0f, 1.0f,
// 	};
// 	
// public:
// 	Dreptunghi()
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
// 		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(100.f, 100.f, 0.0));
// 		
// 		shader->setMat4("modelMatrix", translationMatrix);
// 		shader->setInt("colorCode", 2);
// 		glDrawArrays(GL_POLYGON, 0, 4);
// 	}
//
// 	~Dreptunghi()
// 	{
// 		glDisableVertexAttribArray(0);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &vboId);
// 		
// 		glBindVertexArray(0);
// 		glDeleteVertexArrays(1, &vaoId);
// 	}
// };
//
// Shader* shader = nullptr;
// Axis* axis = nullptr;
// PuncteInColturi* puncteInColturi = nullptr;
// Dreptunghi* dreptunghi = nullptr;
//
// void RenderFunction()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	shader->use();
// 	
// 	glm::mat4 projectionMatrix = glm::ortho(xMin, xMax, yMin, yMax);
// 	// Alta varianta pentru a calcula matricea de proiectie:
// 	// glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(2.f / sceneWidth, 2.f / sceneHeight, 1.0));
// 	// glm::mat4 translateMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-xSceneCenter, -ySceneCenter, 0.0));
// 	// glm::mat4 projectionMatrix = scaleMatrix * translateMatrix;
// 	 
// 	shader->setMat4("projectionMatrix", projectionMatrix);
// 	
// 	axis->render(shader);
// 	puncteInColturi->render(shader);
// 	dreptunghi->render(shader);
// 	
// 	glutSwapBuffers();
// 	glFlush();
// }
//
// int main(int argc, char* argv[])
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
// 	glutInitWindowPosition(100, 100);
// 	glutInitWindowSize(600, 600); 
// 	glutCreateWindow("Utilizare glm::ortho - OpenGL <<nou>>");
// 	glewInit(); 
//
// 	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
// 	shader = new Shader("03_03_Shader.vert", "03_03_Shader.frag");
// 	axis = new Axis();
// 	puncteInColturi = new PuncteInColturi();
// 	dreptunghi = new Dreptunghi();
// 	
// 	glutDisplayFunc(RenderFunction);
// 	glutMainLoop();
//
// 	delete axis;
// 	delete shader;
// 	delete puncteInColturi;
// 	delete dreptunghi;
// }
//
