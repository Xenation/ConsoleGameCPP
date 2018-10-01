#include "stdafx.h"
#include "Graphic.h"


Graphic::Graphic(const char** cont, int width, int height) {
	this->contents = new char*[height];
	this->width = width;
	this->height = height;
	for (int y = 0; y < height; y++) {
		this->contents[y] = new char[width];
		for (int x = 0; x < width; x++) {
			this->contents[y][x] = cont[y][x];
		}
	}
}


Graphic::~Graphic() {
	delete(this->contents);
}

void Graphic::CopyToBuffer(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Pos pos) {
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {
			buffer[pos.y + y][pos.x + x].Char.AsciiChar = this->contents[y][x];
			buffer[pos.y + y][pos.x + x].Attributes = 0x0E;
		}
	}
}
