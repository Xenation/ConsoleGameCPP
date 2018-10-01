#pragma once
#include "Graphic.h"
class ArtGraphic : public Graphic {
public:
	char** contents;
	ArtGraphic(const char** cont, int width, int height);
	~ArtGraphic();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Pos pos);
};
