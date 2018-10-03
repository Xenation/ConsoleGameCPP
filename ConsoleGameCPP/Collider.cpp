#include "stdafx.h"
#include "Collider.h"
#include "PhysicsManager.h"
#include "Entity.h"


Collider::Collider(Entity* entity, Vec2i* pos, Vec2i size) {
	this->entity = entity;
	this->layer = &CollisionLayer::Default;
	this->position = pos;
	this->size = size;
	this->uid = PhysicsManager::getInstance().RegisterCollider(this);
}

Collider::~Collider() {
	PhysicsManager::getInstance().UnregisterCollider(uid);
}

void Collider::Update(std::unordered_map<unsigned int, Collider*>* colliders) {
	
	for (std::pair<unsigned int, Collider*> pair : (*colliders)) {
		if (pair.second == this || !((1 << pair.second->layer->layerIndex) & this->layer->layerMask)) continue;

		if (pair.second->position->x == this->position->x + this->size.x + 1
			&& pair.second->position->y <= this->position->y + this->size.y + 1
			&& pair.second->position->y + pair.second->size.y >= this->position->y - 1) { // Right side touch
			entity->OnCollisionTouch(pair.second, Side::Right);
		}
		if (pair.second->position->x + pair.second->size.x == this->position->x - 1
			&& pair.second->position->y <= this->position->y + this->size.y + 1
			&& pair.second->position->y + pair.second->size.y >= this->position->y - 1) { // Left side touch
			entity->OnCollisionTouch(pair.second, Side::Left);
		}
		if (pair.second->position->y + pair.second->size.y == this->position->y - 1
			&& pair.second->position->x <= this->position->x + this->size.x
			&& pair.second->position->x + pair.second->size.x >= this->position->x) { // Top side touch
			entity->OnCollisionTouch(pair.second, Side::Top);
		}
		if (pair.second->position->y == this->position->y + this->size.y + 1
			&& pair.second->position->x <= this->position->x + this->size.x
			&& pair.second->position->x + pair.second->size.x >= this->position->x) { // Bottom side touch
			entity->OnCollisionTouch(pair.second, Side::Bottom);
		}
	}

}
