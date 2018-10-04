#pragma once

#include "MathStructs.h"
#include "Graphic.h"
#include "Collider.h"

class Camera;
class Entity {
public:
	Vec2i position;
	Graphic* graphic;
	Collider* collider;
	Entity(Graphic* graphic, Vec2i pos, bool hasCollider = false);
	~Entity();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Camera* camera);
	virtual void Update();
	virtual void OnCollisionTouch(Collider* touched, Side side);
};

