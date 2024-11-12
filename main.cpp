// Codul sursa este adaptat dupa OpenGLBook.com

#include "fmi/01-01-square/square-app.h"
#include "fmi/02-01-lines/LineApp.h"
#include "fmi/02-02-triangles/TriangleApp.h"
#include "fmi/06-01-texture/TextureApp.h"
#include "fmi/05-01-star/StarApp.h"

int main(int argc, char* argv[]) {
	//SquareApp* squareApp = SquareApp::getInstance();
	//squareApp->run(argc, argv);

	//LineApp* lineApp = LineApp::getInstance();
	//lineApp->run(argc, argv);

	//TriangleApp* triangleApp = TriangleApp::getInstance();
	//triangleApp->run(argc, argv);

	//TextureApp::getInstance()->run(argc, argv);

	StarApp::getInstance()->run(argc, argv);
}

