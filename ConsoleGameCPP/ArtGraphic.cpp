#include "stdafx.h"

#include "ArtGraphic.h"

#include "Camera.h"


ArtGraphic::ArtGraphic(const char** cont, int width, int height) {
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

ArtGraphic::ArtGraphic(char** cont, int width, int height) {
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

ArtGraphic::~ArtGraphic() {

}
