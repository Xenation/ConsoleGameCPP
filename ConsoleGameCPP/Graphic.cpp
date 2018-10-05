#include "stdafx.h"

#include "Graphic.h"

Graphic::Graphic() {}

Graphic::~Graphic() {
	for (int i = 0; i < height; i++) {
		delete[] contents[i];
	}
	delete[] contents;
	contents = nullptr;
}