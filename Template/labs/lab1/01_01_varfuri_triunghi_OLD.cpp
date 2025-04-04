// //
// // =================================================
// // | Grafica pe calculator                         |
// // =================================================
// // | Laboratorul I - 01_01_varfuri_triunghi_OLD.cpp |
// // =================================================
// //	
// //  Prezentul cod sursa este adaptat dupa OpenGLBook.com;
// //  Program ce deseneaza conturul unui triunghi, folosidu-se tehnicile OLD OpenGL;
//
// #include <GL/freeglut.h>   
//
// void RenderFunction()
// {
//     glClear(GL_COLOR_BUFFER_BIT); 
//     glPointSize(20.0);             
//
//     glBegin(GL_POINTS);
//     glColor4f( 1.0f, 0.0f, 0.0f, 1.0f);  
//     glVertex4f(-0.8f, -0.8f, 0.0f, 1.0f);  
//         
//     glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
//     glVertex4f(0.0f,  0.8f, 0.0f, 1.0f);
//         
//     glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
//     glVertex4f(0.8f, -0.8f, 0.0f, 1.0f);
//     glEnd( );
//     
//     glFlush ( ); 
// }
//
// int main(int argc, char* argv[])
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);              
//     glutInitWindowPosition (100,100);                       
//     glutInitWindowSize(700,500);                            
//     glutCreateWindow("Varfuri triunghi - OpenGL <<vechi>>");
//
//     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);              
//     glutDisplayFunc(RenderFunction);   
//     
//     glutMainLoop();
//   
//     return 0;
// }