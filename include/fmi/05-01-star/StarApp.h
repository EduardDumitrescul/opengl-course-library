#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/Shader.h"
#include "fmi/05-01-star/Star.h"
#include "glm/glm.hpp"		//	Bibloteci utilizate pentru transformari grafice;
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class StarApp {
private:
	static StarApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Animatie: Coordonate Omogene";

	Shader* shader = nullptr;
	Star* star = nullptr;

	glm::mat4 viewMatrix;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static StarApp* getInstance();
	void run(int argc, char* argv[]);
};