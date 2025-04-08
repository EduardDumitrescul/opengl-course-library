// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul I - 01_02_varfuri_triunghi.cpp |
// // ==============================================
// //
// //  Prezentul cod sursa este adaptat dupa OpenGLBook.com;
// //  Program ce deseneaza 3 puncte colorate diferit care reprezinta varfurile unui triunghi, folosidu-se tehnicile MODERN OpenGL;
//
// #include <stdlib.h>       
// #include <GL/glew.h>      
// #include <GL/freeglut.h>
//
// class VarfuriTriunghi
// {
//     GLuint vaoId, vboId, colorBufferId;
//     
//     // De explorat cu mai multe varfuri. Coordonatele sunt (momentan) in intervalul [-1,1]
//     GLfloat vertices[3 * 4] = {
//         -0.8f, -0.8f, 0.0f, 1.0f,
//          0.0f,  0.8f, 0.0f, 1.0f,
//          0.8f, -0.8f, 0.0f, 1.0f,
//         // 0.3f, -0.3f, 0.0f, 1.0f, 
//         // 0.3f, 0.3f, 0.0f, 1.0f
//     };
//
//     GLfloat colors[3 * 4] = {
//         1.0f, 0.0f, 0.0f, 1.0f,
//         0.0f, 1.0f, 0.0f, 1.0f,
//         0.0f, 0.0f, 1.0f, 1.0f,
//         //0.0f, 1.0f, 1.0f, 1.0f,
//         // 1.0f, 0.0f, 1.0f, 1.0f
//     };
//
// public:
//     VarfuriTriunghi()
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
// 		   glBindVertexArray(vaoId);
//         glPointSize(20.0);               
//         glDrawArrays(GL_POINTS, 0, 3);  // De explorat si alte variante de primitive
//  
//     }
//
//     ~VarfuriTriunghi()
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
// GLuint
//   VertexShaderId,
//   FragmentShaderId,
//   ProgramId;
//
// const GLchar* VertexShader =
// {
//       "#version 400\n"\
//
//       "layout(location=0) in vec4 in_Position;\n"\
//       "layout(location=1) in vec4 in_Color;\n"\
//       "out vec4 ex_Color;\n"\
//
//       "void main(void)\n"\
//       "{\n"\
//       "  gl_Position = in_Position;\n"\
//       "  ex_Color = in_Color;\n"\
//       "}\n"
// };
//
// const GLchar* FragmentShader =
// {
//       "#version 400\n"\
//
//       "in vec4 ex_Color;\n"\
//       "out vec4 out_Color;\n"\
//
//       "void main(void)\n"\
//       "{\n"\
//       "  out_Color = ex_Color;\n"\
//       "}\n"
// };
//
// void CreateShaders() {
//     VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(VertexShaderId, 1, &VertexShader, NULL);
//     glCompileShader(VertexShaderId);
//
//     FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(FragmentShaderId, 1, &FragmentShader, NULL);
//     glCompileShader(FragmentShaderId);
//
//     ProgramId = glCreateProgram();
//     glAttachShader(ProgramId, VertexShaderId);
//     glAttachShader(ProgramId, FragmentShaderId);
//     glLinkProgram(ProgramId);
//     glUseProgram(ProgramId);
// }
//
// void DestroyShaders() {  
//     glUseProgram(0);
//
//     glDetachShader(ProgramId, VertexShaderId);
//     glDetachShader(ProgramId, FragmentShaderId);
//
//     glDeleteShader(FragmentShaderId);
//     glDeleteShader(VertexShaderId);
//
//     glDeleteProgram(ProgramId);
// }
//
// VarfuriTriunghi* varfuriTriunghi = nullptr;
//
// void RenderFunction()
// {
//     glClear(GL_COLOR_BUFFER_BIT); 
//     varfuriTriunghi->render();
//     glFlush();
// }
//
// int main(int argc, char* argv[])
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           
//     glutInitWindowPosition(100, 100);                      
//     glutInitWindowSize(700, 500);                          
//     glutCreateWindow("Varfuri triunghi - OpenGL <<nou>>"); 
//     
//     glewInit();
//     glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
//
//     varfuriTriunghi = new VarfuriTriunghi();
//
//     CreateShaders();                    
//     glutDisplayFunc(RenderFunction);    
//     glutCloseFunc(DestroyShaders);      
//     
//     glutMainLoop();
//
//     delete varfuriTriunghi;
//     
//     return 0;
// }