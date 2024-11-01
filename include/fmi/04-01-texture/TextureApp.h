#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/Shader.h"
#include "fmi/Texture.h"
#include "fmi/04-01-texture/Quadrilater.h"

class TextureApp {
private:
	static TextureApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Moduri pentru desenarea liniilor";

	Shader* shader = nullptr;
	Texture* texture = nullptr;
	Quadrilater* quadrilater = nullptr;

	void initialize();
	static void timer(int value);
	static void renderFunction();
	static void cleanup();
public:
	static TextureApp* getInstance();
	void run(int argc, char* argv[]);
};