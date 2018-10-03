#include "stdafx.h"
#include "BouncingEntity.h"


BouncingEntity::BouncingEntity(Graphic* graphic, Pos pos) : Entity::Entity(graphic, pos, true) {
	this->velocity = {1, 1};
}


BouncingEntity::~BouncingEntity() {
	
}

void BouncingEntity::Update() {
	if (position.x + graphic->width >= SCREEN_WIDTH) {
		velocity.x = -1;
	} else if (position.x <= 0) {
		velocity.x = 1;
	}
	if (position.y + graphic->height >= SCREEN_HEIGHT) {
		velocity.y = -1;
	} else if (position.y <= 0) {
		velocity.y = 1;
	}
	position.x += velocity.x;
	position.y += velocity.y;
}

void BouncingEntity::OnCollisionTouch(Collider* touched, Side side) {
	switch (side) {
	case Top:
		velocity.y = 1;
		break;
	case Left:
		velocity.x = 1;
		break;
	case Right:
		velocity.x = -1;
		break;
	case Bottom:
		velocity.y = -1;
		break;
	default:
		break;
	}
}
