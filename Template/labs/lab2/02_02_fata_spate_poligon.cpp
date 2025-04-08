// //
// // =================================================
// // | Grafica pe calculator                         |
// // =================================================
// // | Laboratorul II - 02_02_fata_spate_poligon.cpp |
// // =================================================
// //
// //  Prezentul cod sursa este adaptat dupa OpenGLBook.com;
// //  Program ce deseneaza 2 triunghiuri din spatiul 3D, unul vazut din fata, iar altul din spate, folosidu-se tehnicile MODERN OpenGL;
// //  Sunt ilustrate optiunile GL_FRONT, GL_BACK, etc. legate de fata/spatele poligoanelor si alte functii asociate (glCullFace(), glFrontFace());
// //
// #include <stdlib.h>       
// #include <GL/glew.h>      
// #include <GL/freeglut.h>
//
// #include "Shader.h"
//
// class TriunghiMic
// {
//     GLuint vaoId, vboId, colorBufferId;
//     
//     GLfloat vertices[3 * 4] = {
//         -0.2f, -0.2f, 0.0f, 1.0f,	
//         0.0f,  0.2f, 0.0f, 1.0f,
//         0.2f, -0.2f, 0.0f, 1.0f, 
//     };
//
//     GLfloat colors[3 * 4] = {
//         1.0f, 0.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f,
//     };
//
// public:
//     TriunghiMic()
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
// 		glBindVertexArray(vaoId);
//         shader->setInt("colorCode", 0);
//         glLineWidth(8.0);
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//     }
//
//     ~TriunghiMic()
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
//
//
// class TriunghiMare
// {
//     GLuint vaoId, vboId, colorBufferId;
//     
//     GLfloat vertices[3 * 4] = {
//         -0.8f, -0.6f, 0.0f, 1.0f,
//          0.8f, -0.6f, 0.0f, 1.0f,
//          0.0f,  0.8f, 0.0f, 1.0f
//     };
//
//     GLfloat colors[3 * 4] = {
//         1.0f, 0.0f, 1.0f, 1.0f,
//         1.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 1.0f, 1.0f
//     };
//
// public:
//     TriunghiMare()
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
//         glBindVertexArray(vaoId);
//         shader->setInt("colorCode", 1);
//         glLineWidth(8.0);
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//     }
//
//     ~TriunghiMare()
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
// TriunghiMic* triunghiMic = nullptr;
// TriunghiMare* triunghiMare = nullptr;
//
// void RenderFunction()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     
//     glPolygonMode(GL_FRONT, GL_LINE);
//     //	Modificare 1: schimbare fata poligonului
//     //	Modificare 2: executate randurile de mai jos; testate si GL_BACK, GL_FRONT_AND_BACK
//     // glEnable (GL_CULL_FACE);			
//     // glCullFace (GL_FRONT);
//     //	Modificare 3: executat randul de mai jos, combinate modificarile 
//     // glFrontFace(GL_CW);
//     //  Modificare 4: de folosit variabile de tipul GLuint pentru alegerea fata/spate GLuint mode1=GL_FRONT, etc.;
//     
//     shader->use();
//     triunghiMic->render(shader);
//     triunghiMare->render(shader);
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
//     shader = new Shader("02_02_Shader.vert", "02_02_Shader.frag");
//     triunghiMic = new TriunghiMic();
//     triunghiMare = new TriunghiMare();
//     
//     glutDisplayFunc(RenderFunction);      
//     glutMainLoop();
//
//     delete shader;
//     delete triunghiMic;
//     delete triunghiMare;
//     
//     return 0;
// }
