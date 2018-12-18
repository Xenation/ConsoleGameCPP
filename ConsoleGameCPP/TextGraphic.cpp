#include "stdafx.h"

#include "Graphic.h"

#include "TextGraphic.h"

#include "Camera.h"


TextGraphic::TextGraphic() {
	width = 0;
	contents = nullptr;
	height = 1;
	foregroundColor = ConsoleColor::WHITE;
}

TextGraphic::TextGraphic(const char* text) {
	width = strlen(text);
	contents = new wchar_t*[1];
	contents[0] = new wchar_t[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->contents[0][i] = text[i];
	}
	foregroundColor = ConsoleColor::WHITE;
}


TextGraphic::~TextGraphic() {

}

void TextGraphic::SetText(const char* text) {
	if (contents != nullptr) {
		delete[] contents[0];
		delete[] contents;
		contents = nullptr;
	}
	width = strlen(text);
	if (contents == nullptr) {
		contents = new wchar_t*[1];
	}
	contents[0] = new wchar_t[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->contents[0][i] = text[i];
	}
}

char* TextGraphic::GetText() const {
	char* txt = new char[width];
	for (int i = 0; i < width; i++) {
		txt[i] = contents[0][i];
	}
	return txt;
}
