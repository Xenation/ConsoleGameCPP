#include "stdafx.h"
#include "TextGraphic.h"
#include "Camera.h"


TextGraphic::TextGraphic() {
	width = 0;
	this->text = NULL;
	height = 1;
}

TextGraphic::TextGraphic(const char* text) {
	width = strlen(text);
	this->text = new char[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->text[i] = text[i];
	}
}


TextGraphic::~TextGraphic() {
	delete(this->text);
}

void TextGraphic::setText(const char* text) {
	delete [] this->text;
	width = strlen(text);
	this->text = new char[width];
	height = 1;
	for (int i = 0; i < width; i++) {
		this->text[i] = text[i];
	}
}

char* TextGraphic::getText() {
	char* txt = new char[width];
	for (int i = 0; i < width; i++) {
		txt[i] = text[i];
	}
	return txt;
}

void TextGraphic::Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Vec2i pos, Camera* camera) {
	Box camBox = camera->getBoundingBox();
	Vec2i screenPos = pos - camera->getPosition();
	for (int i = 0; i < this->width; i++) {
		if (!isInBox(camBox, { pos.x + i, pos.y })) continue;
		buffer[screenPos.y][screenPos.x + i].Char.AsciiChar = this->text[i];
		buffer[screenPos.y][screenPos.x + i].Attributes = 0x0E;
	}
}
