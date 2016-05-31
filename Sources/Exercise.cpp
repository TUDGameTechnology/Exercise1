#include "pch.h"

#include <Kore/IO/FileReader.h>
#include "SimpleGraphics.h"
#include <Kore/System.h>

using namespace Kore;

namespace {
	void update() {
		startFrame();

		// Draw something right here using setPixel(...)
		endFrame();
	}
}

int kore(int argc, char** argv) {
	Kore::System::setName("TUD Game Technology - ");
	Kore::System::setup();
	Kore::WindowOptions options;
	options.title = "Exercise 1";
	options.width = width;
	options.height = height;
	options.x = 100;
	options.y = 100;
	options.targetDisplay = -1;
	options.mode = WindowModeWindow;
	options.rendererOptions.depthBufferBits = 16;
	options.rendererOptions.stencilBufferBits = 8;
	options.rendererOptions.textureFormat = 0;
	options.rendererOptions.antialiasing = 0;
	Kore::System::initWindow(options);

	initGraphics();
	Kore::System::setCallback(update);
	
	Kore::System::start();

	return 0;
}
