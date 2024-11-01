#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/02-01-lines/LinePoints.h"
#include "fmi/02-01-lines/Lines.h"
#include "fmi/02-01-lines/LineLoop.h"
#include "fmi/02-01-lines/LineStrip.h"
#include "fmi/Shader.h"

class LineApp {
private:
	static LineApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Moduri pentru desenarea liniilor";

	Shader* shader = nullptr;
	LinePoints* points = nullptr;
	Lines* lines = nullptr;
	LineLoop* lineLoop = nullptr;
	LineStrip* lineStrip = nullptr;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static LineApp* getInstance();
	void run(int argc, char* argv[]);
};