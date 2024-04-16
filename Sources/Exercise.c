#include <stdlib.h>

#include <kinc/graphics1/graphics.h>
#include <kinc/io/filereader.h>
#include <kinc/system.h>

const int width = 512;
const int height = 512;

void update() {
	kinc_g1_begin();

	//////////////////////////////////////////////////////////////////////////
	// Exercise 1
	//////////////////////////////////////////////////////////////////////////
	// Draw something right here using kinc_g1_set_pixel(...)

	kinc_g1_end();
}

int kickstart(int argc, char** argv) {
	kinc_init("Exercise 1", width, height, NULL, NULL);

	kinc_g1_init(width, height);
	kinc_set_update_callback(update, NULL);

	kinc_start();

	return EXIT_SUCCESS;
}
