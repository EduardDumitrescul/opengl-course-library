#include "fmi/05-01-star/StarApp.h"

StarApp* StarApp::instance = nullptr;

void StarApp::run(int argc, char* argv[])
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

void StarApp::initialize()
{
	shader = new Shader("shaders/05-01-star/star.vert", "shaders/05-01-star/star.frag");
	star = new Star();
	viewMatrix = glm::ortho(-200.f, 200.f, -200.f, 200.f);
}

void StarApp::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	instance->shader->use();
	instance->shader->setMat4("viewMatrix", instance->viewMatrix);
	instance->star->render();
	instance->shader->remove();

	glFlush();
}

void StarApp::cleanup()
{
	instance->star->cleanup();
}

StarApp* StarApp::getInstance() {
	if (instance == nullptr) {
		instance = new StarApp();
	}
	return instance;
}


