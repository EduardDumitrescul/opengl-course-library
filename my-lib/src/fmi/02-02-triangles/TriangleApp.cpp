#include "fmi/02-02-triangles/TriangleApp.h"

TriangleApp* TriangleApp::instance = nullptr;

void TriangleApp::run(int argc, char* argv[])
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

void TriangleApp::initialize()
{
	shader = new Shader("shaders/02-02-triangles/triangles.vert", "shaders/02-02-triangles/triangles.frag");
	points = new TrianglePoints();
	triangles = new Triangles();
	triangleFan = new TriangleFan();
	triangleStrip = new TriangleStrip();
}

void TriangleApp::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	instance->shader->use();
	instance->points->render();
	instance->triangles->render();
	instance->triangleFan->render();
	instance->triangleStrip->render();
	instance->shader->remove();

	glFlush();
}

void TriangleApp::cleanup()
{
	instance->points->cleanup();
	instance->triangles->cleanup();
	instance->triangleFan->cleanup();
	instance->triangleStrip->cleanup();
}

TriangleApp* TriangleApp::getInstance() {
	if (instance == nullptr) {
		instance = new TriangleApp();
	}
	return instance;
}


