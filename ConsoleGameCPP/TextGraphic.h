#pragma once
#include "Graphic.h"
class TextGraphic : public Graphic {
public:
	TextGraphic();
	TextGraphic(const char* text);
	~TextGraphic();
	void setText(const char* text);
	char* getText();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Pos pos);
private:
	char* text;
};

