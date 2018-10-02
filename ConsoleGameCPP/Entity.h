#pragma once

#include "MathStructs.h"
#include "Graphic.h"
#include "Collider.h"

class Entity {
public:
	Pos position;
	Graphic* graphic;
	Collider* collider;
	Entity(Graphic* graphic, Pos pos, bool hasCollider = false);
	~Entity();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
	virtual void Update();
	virtual void OnCollisionTouch(Collider* touched);
};

