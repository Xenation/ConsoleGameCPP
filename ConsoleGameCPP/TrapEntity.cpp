#include "stdafx.h"
#include "TrapEntity.h"


TrapEntity::TrapEntity(Graphic* graphic, Vec2i pos) : Entity::Entity(graphic, pos, true) {
	this->collider->layer = &CollisionLayer::Enemy;
}


TrapEntity::~TrapEntity()
{
}
