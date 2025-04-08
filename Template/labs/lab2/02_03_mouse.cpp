// //
// // =================================================
// // | Grafica pe calculator                         |
// // =================================================
// // | Laboratorul II - 02_03_mouse.cpp |
// // =================================================
// //
// //  Prezentul cod sursa este adaptat dupa OpenGLBook.com;
// // Program ce desenaza 2 patrate din spatiul 3D, unul vazut din fata, iar altul din spate, 
// // si demonstreaza cum putem interactiona cu programul nostru folosind mouse-ul.
//
// #include <stdlib.h>       
// #include <GL/glew.h>      
// #include <GL/freeglut.h>
//
// #include "Shader.h"
//
// class Obiect
// {
//     GLuint vaoId, vboId, colorBufferId;
//     
//     GLfloat vertices[8 * 4] = {
//         //	Patrat "mare"
//         0.5f, -0.5f, 0.0f, 1.0f,
//        -0.5f, -0.5f, 0.0f, 1.0f,
//        -0.5f, 0.5f, 0.0f, 1.0f,
//         0.5f, 0.5f, 0.0f, 1.0f,
//         //	Patrat "mic"
//         0.3f, 0.3f, 0.0f, 1.0f,
//        -0.3f, 0.3f, 0.0f, 1.0f,
//        -0.3f, -0.3f, 0.0f, 1.0f,
//         0.3f, -0.3f, 0.0f, 1.0f
//    };
//
//     GLfloat colors[8 * 4] = {
//         //	Patrat "mare"
//         1.0f, 0.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f,
//         1.0f, 1.0f, 0.0f, 1.0f,
//         //	Patrat "mic"
//         1.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         1.0f, 0.0f, 0.0f, 1.0f,
//     };
//
// public:
//     Obiect()
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
//     void render() const
//     {
//         glBindVertexArray(vaoId);
//         glLineWidth(8.0);
//         glPolygonMode(GL_FRONT, GL_FILL);	
//         glPolygonMode(GL_BACK, GL_LINE);
//         glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//         glDrawArrays(GL_QUADS, 4, 4);
//     }
//
//     ~Obiect()
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
// Obiect* obiect = nullptr;
//
// void RenderFunction()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     shader->use();
//     obiect->render();
//     glFlush();
// }
//
// void UseMouse(int button, int state, int x, int y)
// {
//     switch (button) {
//         case GLUT_LEFT_BUTTON:		
//             if (state == GLUT_DOWN)
//             {
//                 shader->setInt("colorCode", 1);
//             }
//             break;
//         case GLUT_RIGHT_BUTTON:		
//             if (state == GLUT_DOWN)
//             {
//                 shader->setInt("colorCode", 0);
//
//             }
//             break;
//         default:
//             break;
//     }
// }
//
// int main(int argc, char* argv[])
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           
//     glutInitWindowPosition(100, 100);                      
//     glutInitWindowSize(700, 500);                          
//     glutCreateWindow("Poligoane 3D. Functii pentru mouse");
//     
//     glewInit();
//
//     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//     
//     shader = new Shader("02_03_Shader.vert", "02_03_Shader.frag");
//     obiect = new Obiect();
//     
//     glutDisplayFunc(RenderFunction);
//     glutMouseFunc(UseMouse);
//     glutMainLoop();
//
//     delete shader;
//     delete obiect;
//     
//     return 0;
// }
