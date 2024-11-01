#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/01-01-square/square.h"
#include "fmi/Shader.h"

class SquareApp {
private:
	static SquareApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Grafica pe Calculator";

	Shader* squareShader = nullptr;
	Square* square = nullptr;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static SquareApp* getInstance();
	void run(int argc, char* argv[]);
};