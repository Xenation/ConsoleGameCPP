#include "stdafx.h"

#include "ArtGraphic.h"

#include "Camera.h"


ArtGraphic::ArtGraphic(const wchar_t** cont, int width, int height) {
	this->contents = new wchar_t*[height];
	this->width = width;
	this->height = height;
	for (int y = 0; y < height; y++) {
		this->contents[y] = new wchar_t[width];
		for (int x = 0; x < width; x++) {
			this->contents[y][x] = cont[y][x];
		}
	}
	foregroundColor = ConsoleColor::WHITE;
}

ArtGraphic::ArtGraphic(wchar_t** cont, int width, int height) {
	this->contents = new wchar_t*[height];
	this->width = width;
	this->height = height;
	for (int y = 0; y < height; y++) {
		this->contents[y] = new wchar_t[width];
		for (int x = 0; x < width; x++) {
			this->contents[y][x] = cont[y][x];
		}
	}
	foregroundColor = ConsoleColor::WHITE;
}

ArtGraphic::~ArtGraphic() {

}
