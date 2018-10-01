#pragma once

#include "MathStructs.h"
#include "Graphic.h"

class Entity {
public:
	Pos position;
	Graphic* graphic;
	Entity(Graphic* graphic, Pos pos);
	~Entity();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
	virtual void Update();
};

