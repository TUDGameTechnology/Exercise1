#include <stdlib.h>

#include <kinc/graphics1/graphics.h>
#include <kinc/io/filereader.h>
#include <kinc/system.h>

#define WIDTH 512
#define HEIGHT 512

void update(void* data) {
	kinc_g1_begin();

	//////////////////////////////////////////////////////////////////////////
	// Exercise 1
	//////////////////////////////////////////////////////////////////////////
	// Draw something right here using kinc_g1_set_pixel(...)

	kinc_g1_end();
}

int kickstart(int argc, char** argv) {
	kinc_init("Exercise 1", WIDTH, HEIGHT, NULL, NULL);

	kinc_g1_init(WIDTH, HEIGHT);
	kinc_set_update_callback(update, NULL);

	kinc_start();

	return EXIT_SUCCESS;
}
