// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul II - 02_01_primitive.cpp |
// // ==============================================
// //
// //  Prezentul cod sursa este adaptat dupa OpenGLBook.com;
// // Program ce deseneaza 6 puncte unite de o linie poligonala, folosidu-se tehnicile MODERN OpenGL;
// #include <stdlib.h>       
// #include <GL/glew.h>      
// #include <GL/freeglut.h>
//
// #include "Shader.h"
//
// class Primitive
// {
//     GLuint vaoId, vboId, colorBufferId;
//     
//     GLfloat vertices[6 * 4] = {
//         -0.2f, -0.2f, 0.0f, 1.0f,
//          0.0f,  0.2f, 0.0f, 1.0f,
//          0.2f, -0.2f, 0.0f, 1.0f,
//         -0.8f, -0.8f, 0.0f, 1.0f,
//          0.0f,  0.8f, 0.0f, 1.0f,
//          0.8f, -0.8f, 0.0f, 1.0f
//     };
//
//     GLfloat colors[6 * 4] = {
//         1.0f, 0.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f,
//         1.0f, 0.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f
//     };
//
// public:
//     Primitive()
//     {
//         glGenVertexArrays(1, &vaoId);
//         glBindVertexArray(vaoId);
// 	
//         glGenBuffers(1, &vboId);
//         glBindBuffer(GL_ARRAY_BUFFER, vboId);
//         glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//         glEnableVertexAttribArray(0);
//         glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
//
//         glGenBuffers(1, &colorBufferId);
//         glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);
//         glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
//
//         glEnableVertexAttribArray(1);
//         glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
//     }
//
//     void render(const Shader* shader) const
//     {
// 		    glBindVertexArray(vaoId);
//         shader->setInt("colorCode", 0);
//         glLineWidth(5.0);
//         glDrawArrays(GL_LINE_STRIP, 0, 6);
//
//         shader->setInt("colorCode", 1);
//         glEnable(GL_POINT_SMOOTH);
//         glPointSize(20.0);				  
//         glDrawArrays(GL_POINTS, 0, 6);
//         glDisable(GL_POINT_SMOOTH);
//     }
//
//     ~Primitive()
//     {
//         glDisableVertexAttribArray(1);
//         glDisableVertexAttribArray(0);
//
//         glBindBuffer(GL_ARRAY_BUFFER, 0);
//         glDeleteBuffers(1, &colorBufferId);
//         glDeleteBuffers(1, &vboId);
//
//         glBindVertexArray(0);
//         glDeleteVertexArrays(1, &vaoId);
//     }
// };
//
// Shader* shader = nullptr;
// Primitive* primitive = nullptr;
//
// void RenderFunction()
// {
//     glClear(GL_COLOR_BUFFER_BIT); 
//     shader->use();
//     primitive->render(shader);
//     glFlush();
// }
//
// int main(int argc, char* argv[])
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           
//     glutInitWindowPosition(100, 100);                      
//     glutInitWindowSize(700, 500);                          
//     glutCreateWindow("Primitive si culori - OpenGL <<nou>>");
//     
//     glewInit();
//
//     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//     
//     shader = new Shader("02_01_Shader.vert", "02_01_Shader.frag");
//     primitive = new Primitive();
//     
//     glutDisplayFunc(RenderFunction);      
//     glutMainLoop();
//
//     delete shader;
//     delete primitive;
//     
//     return 0;
// }