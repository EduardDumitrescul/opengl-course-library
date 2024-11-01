#include "fmi/04-01-texture/TextureApp.h"

TextureApp* TextureApp::instance = nullptr;

void TextureApp::run(int argc, char* argv[])
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

void TextureApp::timer(int value) {
	// Schedule the next frame
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void TextureApp::initialize()
{
	shader = new Shader("shaders/04-01-texture/quadrilater.vert", "shaders/04-01-texture/quadrilater.frag");
	texture = new Texture("textures/04-01-texture/checkerboard.png");
	quadrilater = new Quadrilater(shader, texture);
}

void TextureApp::renderFunction()
{
	instance->quadrilater->update();
	glClear(GL_COLOR_BUFFER_BIT);
	instance->quadrilater->render();

	glutPostRedisplay();
	glFlush();
}

void TextureApp::cleanup()
{
	instance->quadrilater->cleanup();
}

TextureApp* TextureApp::getInstance() {
	if (instance == nullptr) {
		instance = new TextureApp();
	}
	return instance;
}


