#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/Shader.h"
#include "fmi/04-01-transform/TransformObj.h"
#include "glm/glm.hpp"		//	Bibloteci utilizate pentru transformari grafice;
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class TransformApp {
private:
	static TransformApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Animatie: Efectuarea Rotatiilor si a Scalarilor";

	Shader* shader = nullptr;
	TransformObj* obj = nullptr;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static TransformApp* getInstance();
	void run(int argc, char* argv[]);
};