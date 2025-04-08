// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul III - 03_04_rotire.cpp |
// // ======================================
// //
// //	Program care utilizeaza compunerea transformarilor si rotatia cu un centru diferit de origine;
// //	Se vor desena un patrat si rotatia sa, folosindu-se tehnicile MODERN OpenGL;
// #include <GL/glew.h> 
// #include <GL/freeglut.h> 
// #include "Shader.h"
// #include "glm/ext/matrix_clip_space.hpp"
// #include "glm/gtx/transform.hpp"
//
// float xMin = -400.f, xMax = 400.f, yMin = -300.f, yMax = 300.f;
//
// class Axis
// {
// 	GLuint vaoId, vboId, colorBufferId;
// 	GLfloat vertices[4 * 4] = {
// 		-400.0f, 0.0f, 0.0f, 1.0f,
// 		400.0f,  0.0f, 0.0f, 1.0f,
// 		0.0f, -300.0f, 0.0f, 1.0f,
// 		0.0f, 300.0f, 0.0f, 1.0f,
// 	};
//
// 	GLfloat colors[4 * 4] = {
// 		1.0f, 0.0f, 0.0f, 1.0f,
// 		0.0f, 1.0f, 0.0f, 1.0f,
// 		0.0f, 0.0f, 1.0f, 1.0f,
// 		1.0f, 0.0f, 0.0f, 1.0f,
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
//
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
// 		
// 		glLineWidth(1.0);
// 		glDrawArrays(GL_LINES, 0, 4);
// 	}
//
// 	~Axis()
// 	{
// 		glDisableVertexAttribArray(0);
// 		glDisableVertexAttribArray(1);
//
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 		glDeleteBuffers(1, &vboId);
// 		glDeleteBuffers(1, &colorBufferId);
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
// 		50.0f,  50.0f, 0.0f, 1.0f,
// 		50.0f, 150.0f, 0.0f, 1.0f,
// 		150.0f,  150.0f, 0.0f, 1.0f,
// 		150.0f,  50.0f, 0.0f, 1.0f,
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
// 		shader->setMat4("modelMatrix", glm::mat4(1.0f));
// 		shader->setInt("colorCode", 1);
// 		glDrawArrays(GL_POLYGON, 0, 4);
//
// 		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-100.f, -100.f, 0.0));
// 		glm::mat4 translationMatrixInverse = glm::translate(glm::mat4(1.0f), glm::vec3(100.f, 100.f, 0.0));
// 		GLfloat angle = 3.1415 / 8; 
// 		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 0.0, 1.0));
//
// 		glm::mat4 modelMatrix = translationMatrixInverse * rotationMatrix * translationMatrix;
// 		shader->setMat4("modelMatrix", modelMatrix);
// 		shader->setInt("colorCode", 2);
// 		glLineWidth(4.0);
// 		glDrawArrays(GL_LINE_LOOP, 0, 4);
// 		
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
// Dreptunghi* dreptunghi = nullptr;
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
// 	glutCreateWindow("Rotirea unui patrat in jurul centrului sau - OpenGL <<nou>>");
// 	glewInit(); 
//
// 	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
// 	shader = new Shader("03_04_Shader.vert", "03_04_Shader.frag");
// 	axis = new Axis();
// 	dreptunghi = new Dreptunghi();
// 	
// 	glutDisplayFunc(RenderFunction);
// 	glutMainLoop();
//
// 	delete axis;
// 	delete shader;
// 	delete dreptunghi;
// }
//
