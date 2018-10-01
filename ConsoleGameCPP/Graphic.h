#pragma once

#include "Windows.h"
#include "MathStructs.h";
#include "Constants.h"

class Graphic {
public:
	int width;
	int height;
	char** contents;
	Graphic(const char** cont, int width, int height);
	~Graphic();
	virtual void CopyToBuffer(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Pos pos);
};

