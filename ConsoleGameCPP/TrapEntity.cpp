#include "stdafx.h"

#include "MathStructs.h"

#include "TrapEntity.h"

#include "Collider.h"
#include "CollisionLayer.h"


TrapEntity::TrapEntity(Graphic* graphic, Vec2i pos) : Entity::Entity(graphic, pos, true) {
	this->collider->SetLayer(&CollisionLayer::Trap);
	this->collider->SetIsStatic(false);
}


TrapEntity::~TrapEntity()
{
}
