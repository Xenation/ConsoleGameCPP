#pragma once

#include "Windows.h"
#include "MathStructs.h"
#include "Constants.h"

class Graphic {
public:
	int width = 0;
	int height = 0;
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Pos pos) = 0;
};

