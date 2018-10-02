#pragma once

#include "Entity.h"

class BouncingEntity : public Entity {
public:
	BouncingEntity(Graphic* graphic, Pos pos);
	~BouncingEntity();
	virtual void Update();
	virtual void OnCollisionTouch(Collider* touched, Side side);
private:
	Pos velocity;
};

