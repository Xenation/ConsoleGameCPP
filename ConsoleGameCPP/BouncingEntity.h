#pragma once

#include "Entity.h"

class BouncingEntity : public Entity {
public:
	BouncingEntity(Graphic* graphic, Vec2i pos);
	~BouncingEntity();
	virtual void Update();
	virtual void OnCollisionTouch(Collider* touched, Side side);
private:
	Vec2i velocity;
};

