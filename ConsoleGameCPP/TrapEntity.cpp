#include "stdafx.h"

#include "MathStructs.h"

#include "TrapEntity.h"

#include "Collider.h"
#include "CollisionLayer.h"


TrapEntity::TrapEntity(Graphic* graphic, Vec2i pos) : Entity::Entity(graphic, pos, true) {
	this->collider->layer = &CollisionLayer::Trap;
}


TrapEntity::~TrapEntity()
{
}
