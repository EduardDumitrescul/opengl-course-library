// //
// // ================================================
// // | Grafica pe calculator                        |
// // ================================================
// // | Laboratorul III - 03_01_animatie_OLD.cpp |
// // ============================================
// //
// //	Program ce deseneaza un dreptunghi ce se deplaseaza stanga-dreapta si are un patrat ce orbiteaza in jurul sau, folosindu-se tehnicile OLD OpenGL;
// //  ELEMENTE DE NOUTATE:
// //	- gluOrtho2D (indica dreptunghiul care este decupat) - DEPRECATED
// //	- glTranslate, glRotate, glPushMatrix, glPopMatrix (pentru transformari; DEPRECATED)
// //	- glutSwapBuffers (v. GLUT_DOUBLE); glutPostRedisplay; glutIdleFunc (animatie)
// //
//
//
// #include <windows.h>       
// #include <GL/freeglut.h>   
//
// static GLdouble position = 0.0;		
// static GLdouble angle = 0.0;		
// static GLdouble alpha = 1.0;
//
// GLint winWidth = 800, winHeight = 600;
// GLfloat xMin = 0, yMin = 0, xMax = 800.0, yMax = 600.0;
//
// void RenderFunction()
// {
// 	glClear(GL_COLOR_BUFFER_BIT);		
// 	glPushMatrix();
// 	glTranslated(position, 200.0, 0.0);	
// 	glPushMatrix();
// 	glRotated(angle, 0.0, 0.0, 1.0);
// 	glColor3f(1.0, 0.0, 0.0);
// 	glRecti(-5, 30, 5, 40);		
// 	glPopMatrix();
// 	glPopMatrix();
// 	
// 	glPushMatrix();
// 	glTranslated (position, 200.0, 0.0);
// 	
// 	glColor3f(0.0, 0.0, 1.0);
// 	glRecti(-20, -12, 20, 12);		
// 	glPopMatrix();
//
// 	glutSwapBuffers();
// 	glFlush();			
// }
//
// void IdleFunction()
// {
// 	position = position + alpha;
// 	angle = angle + 0.1;	
// 	if (position < xMin + 20)	
// 		alpha = 0.1;		
// 	else if (position > xMax - 20)
// 		alpha = -0.1;	
// 	glutPostRedisplay();
// }
//
// void UseMouse(int button, int state, int x, int y)
// {
// 	switch (button) {
// 	case GLUT_LEFT_BUTTON:			
// 		if (state == GLUT_DOWN)
// 			alpha = -0.1;				
// 		break;
// 	case GLUT_RIGHT_BUTTON:		
// 		if (state == GLUT_DOWN)
// 			alpha = 0.1; 
// 		break;
// 	default:
// 		break;
// 	}
// }
//
// int main(int argc, char** argv)
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);					
// 	glutInitWindowPosition(100, 100);								
// 	glutInitWindowSize(winWidth, winHeight);						
// 	glutCreateWindow("Dreptunghi cu satelit - OpenGL <<vechi>>");
//
// 	glClearColor(1.0, 1.0, 1.0, 0.0);			
// 	gluOrtho2D(xMin, xMax, yMin, yMax);			
// 	
// 	glutDisplayFunc(RenderFunction);
// 	glutMouseFunc(UseMouse);
// 	glutIdleFunc(IdleFunction);
// 	
// 	glutMainLoop();
//
// 	return 0;
// }