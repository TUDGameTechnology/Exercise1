#include "pch.h"
#include "SimpleGraphics.h"
#include <Kore/IO/FileReader.h>
#include <Kore/Graphics/Graphics.h>
#include <Kore/Graphics/Shader.h>
#include <Kore/IO/FileReader.h>
#include <limits>

using namespace Kore;

namespace {
	Shader* vertexShader;
	Shader* fragmentShader;
	Program* program;
	TextureUnit tex;
	VertexBuffer* vb;
	IndexBuffer* ib;
	Texture* texture;
	int* image;
}

void startFrame() {
	Graphics::begin();
	image = (int*)texture->lock();
}

void setPixel(int x, int y, float red, float green, float blue) {
	if (x < 0 || x >= width || y < 0 || y >= height) return;
	int r = (int)(red * 255);
	int g = (int)(green * 255);
	int b = (int)(blue * 255);
	image[y * texture->texWidth + x] = 0xff << 24 | r << 16 | g << 8 | b;
}

void endFrame() {
	texture->unlock();

	Graphics::clear(Graphics::ClearColorFlag, 0xff000000);
	
	program->set();
	Graphics::setTexture(tex, texture);
	Graphics::setVertexBuffer(*vb);
	Graphics::setIndexBuffer(*ib);
	Graphics::drawIndexedVertices();

	Graphics::end();
	Graphics::swapBuffers();
}

void initGraphics() {
	FileReader vs("shader.vert");
	FileReader fs("shader.frag");
	vertexShader = new Shader(vs.readAll(), vs.size(), VertexShader);
	fragmentShader = new Shader(fs.readAll(), fs.size(), FragmentShader);
	VertexStructure structure;
	structure.add("pos", Float3VertexData);
	structure.add("tex", Float2VertexData);
	program = new Program;
	program->setVertexShader(vertexShader);
	program->setFragmentShader(fragmentShader);
	program->link(structure);

	tex = program->getTextureUnit("tex");

	texture = new Texture(width, height, Image::RGBA32, false);
	image = (int*)texture->lock();
	for (int y = 0; y < texture->texHeight; ++y) {
		for (int x = 0; x < texture->texWidth; ++x) {
			image[y * texture->texWidth + x] = 0;
		}
	}
	texture->unlock();

	// Correct for the difference between the texture's desired size and the actual power of 2 size
	float xAspect = (float) texture->width / texture->texWidth;
	float yAspect = (float) texture->height / texture->texHeight;
	

	vb = new VertexBuffer(4, structure, 0);
	float* v = vb->lock();
	{
		int i = 0;
		v[i++] = -1; v[i++] = 1; v[i++] = 0.5; v[i++] = 0; v[i++] = 0;
		v[i++] = 1;  v[i++] = 1; v[i++] = 0.5; v[i++] = xAspect; v[i++] = 0;
		v[i++] = 1; v[i++] = -1;  v[i++] = 0.5; v[i++] = xAspect; v[i++] = yAspect;
		v[i++] = -1; v[i++] = -1;  v[i++] = 0.5; v[i++] = 0; v[i++] = yAspect;
	}
	vb->unlock();

	ib = new IndexBuffer(6);
	int* ii = ib->lock();
	{
		int i = 0;
		ii[i++] = 0; ii[i++] = 1; ii[i++] = 3;
		ii[i++] = 1; ii[i++] = 2; ii[i++] = 3;
	}
	ib->unlock();
}
