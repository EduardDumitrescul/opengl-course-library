// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul I - 01_00_test_version.cpp       |
// // ================================================
// //	
// // Program de verificare a versiunii de OpenGL si a GLSL;
// //
//
// #include <cstdio>
// #include <GL/glew.h>        
// #include <GL/freeglut.h>   
//
// int main (int argc, char** argv) {
//
//     glutInit (&argc, argv); 
//     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
//     glutInitWindowPosition (1100, 100);			
//     glutInitWindowSize (600, 400);				
//     int winID = glutCreateWindow ("GL_VERSION");
//     glutDestroyWindow(winID);
//     GLenum err = glewInit();
//     if (err != GLEW_OK)
//     {
//         fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
//         exit(-1);
//     }
//
//     printf("OpenGL version supported by this platform: (%s) \n", glGetString(GL_VERSION)); 
//     printf("GLSL version supported by this platform: (%s) \n", glGetString(GL_SHADING_LANGUAGE_VERSION)); 
//
//     return 0;
// }
