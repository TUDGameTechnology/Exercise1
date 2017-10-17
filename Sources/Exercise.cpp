#include "pch.h"

#include <Kore/IO/FileReader.h>
#include <Kore/System.h>
#include <Kore/Graphics1/Graphics.h>

const int width = 512;
const int height = 512;

using namespace Kore;

namespace {
	void update() {
		Graphics1::begin();

		//////////////////////////////////////////////////////////////////////////
		// Exercise 1
		//////////////////////////////////////////////////////////////////////////
		// Draw something right here using Graphics1::setPixel(...)

		Graphics1::end();
	}
}

int kore(int argc, char** argv) {
	System::init("Exercise 1", width, height);

	Graphics1::init(width, height);
	Kore::System::setCallback(update);
	
	Kore::System::start();

	return 0;
}
