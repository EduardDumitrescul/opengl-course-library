#pragma once

#include <windows.h>  // biblioteci care urmeaza sa fie incluse
#include <stdlib.h> // necesare pentru citirea shader-elor
#include <GL/glew.h> // glew apare inainte de freeglut
#include <GL/freeglut.h>
#include <string>
#include "fmi/02-02-triangles/TrianglePoints.h"
#include "fmi/02-02-triangles/Triangles.h"
#include "fmi/02-02-triangles/TriangleFan.h"
#include "fmi/02-02-triangles/TriangleStrip.h"
#include "fmi/Shader.h"

class TriangleApp {
private:
	static TriangleApp* instance;

	int windowPositionX = 100, windowPositionY = 100;
	int windowHeight = 600, windowWidth = 600;
	std::string windowTitle = "Moduri pentru desenarea liniilor";

	Shader* shader = nullptr;
	TrianglePoints* points = nullptr;
	Triangles* triangles = nullptr;
	TriangleFan* triangleFan = nullptr;
	TriangleStrip* triangleStrip = nullptr;

	void initialize();
	static void renderFunction();
	static void cleanup();
public:
	static TriangleApp* getInstance();
	void run(int argc, char* argv[]);
};