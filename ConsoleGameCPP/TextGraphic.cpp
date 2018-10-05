#include "stdafx.h"

#include "Graphic.h"

#include "TextGraphic.h"

#include "Camera.h"


TextGraphic::TextGraphic() {
	width = 0;
	contents = nullptr;
	height = 1;
}

TextGraphic::TextGraphic(const char* text) {
	width = strlen(text);
	contents = new char*[1];
	contents[0] = new char[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->contents[0][i] = text[i];
	}
}


TextGraphic::~TextGraphic() {

}

void TextGraphic::setText(const char* text) {
	if (contents != nullptr) {
		delete[] contents[0];
		delete[] contents;
		contents = nullptr;
	}
	width = strlen(text);
	if (contents == nullptr) {
		contents = new char*[1];
	}
	contents[0] = new char[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->contents[0][i] = text[i];
	}
}

char* TextGraphic::getText() {
	char* txt = new char[width];
	for (int i = 0; i < width; i++) {
		txt[i] = contents[0][i];
	}
	return txt;
}
