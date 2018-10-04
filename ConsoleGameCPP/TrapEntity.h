#pragma once
#include "Entity.h"
class TrapEntity : public Entity
{
public:
	TrapEntity(Graphic* graphic, Vec2i pos);
	~TrapEntity();
};

