#include "fmi/02-01-lines/LineApp.h"

LineApp* LineApp::instance = nullptr;

void LineApp::run(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(windowPositionX, windowPositionY); // pozitia initiala a ferestrei
	glutInitWindowSize(windowWidth, windowHeight); //dimensiunile ferestrei
	glutCreateWindow(windowTitle.c_str()); // titlul ferestrei

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glewInit(); // nu uitati de initializare glew; trebuie initializat inainte de a a initializa desenarea

	initialize();

	glutDisplayFunc(renderFunction);
	glutCloseFunc(cleanup);
	glutMainLoop();
}

void LineApp::initialize()
{
	shader = new Shader("shaders/02-01-lines/lines.vert", "shaders/02-01-lines/lines.frag");
	points = new LinePoints();
	lines = new Lines();
	lineLoop = new LineLoop();
	lineStrip = new LineStrip();
}

void LineApp::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	instance->shader->use();
	instance->points->render();
	instance->lines->render();
	instance->lineLoop->render();
	instance->lineStrip->render();
	instance->shader->remove();

	glFlush();
}

void LineApp::cleanup()
{
	instance->points->cleanup();
	instance->lines->cleanup();
	instance->lineLoop->cleanup();
	instance->lineStrip->cleanup();
}

LineApp* LineApp::getInstance() {
	if (instance == nullptr) {
		instance = new LineApp();
	}
	return instance;
}


