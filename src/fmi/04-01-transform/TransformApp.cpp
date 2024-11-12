#include "fmi/04-01-transform/TransformApp.h"

TransformApp* TransformApp::instance = nullptr;

void TransformApp::run(int argc, char* argv[])
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
	//glutTimerFunc(timer);
	glutMainLoop();
}

void TransformApp::initialize()
{
	shader = new Shader("shaders/04-01-transform/transform.vert", "shaders/04-01-transform/transform.frag");
	obj = new TransformObj();
}

void TransformApp::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	instance->shader->use();
	glm::mat4 transformMatrix;

	glm::mat4 viewMatrix = glm::ortho(-100.f, 100.f, -100.f, 100.f);
	glm::mat4 translateBack = glm::translate(glm::mat4(1), instance->obj->getTranslate2());
	glm::mat4 rotate = glm::rotate(glm::mat4(1), instance->obj->getAngle(), { 0, 0, 1 });
	glm::mat4 scale = glm::scale(glm::mat4(1), instance->obj->getScale());
	glm::mat4 translateToOrigin = glm::translate(glm::mat4(1), instance->obj->getTranslate1());

	transformMatrix = viewMatrix * translateBack * rotate * scale * translateToOrigin;

	instance->shader->setMat4("transformMatrix", transformMatrix);

	instance->obj->update();
	instance->obj->render();
	instance->shader->remove();

	glutPostRedisplay();
	glFlush();
}

void TransformApp::cleanup()
{
	instance->obj->cleanup();
}

TransformApp* TransformApp::getInstance() {
	if (instance == nullptr) {
		instance = new TransformApp();
	}
	return instance;
}


