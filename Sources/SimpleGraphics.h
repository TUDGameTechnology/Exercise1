#pragma once

void initGraphics();
void startFrame();
void endFrame();
void setPixel(int x, int y, float red, float green, float blue);
// Watch out: If you set one or both values higher than your screen resolution, you can get errors.
const int width = 512;
const int height = 512;
