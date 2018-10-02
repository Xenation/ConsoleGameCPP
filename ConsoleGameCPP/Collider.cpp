#include "stdafx.h"
#include "Collider.h"
#include "PhysicsManager.h"
#include "Entity.h"


Collider::Collider(Entity* entity, Pos* pos, Pos size) {
	this->entity = entity;
	this->position = pos;
	this->size = size;
	this->uid = PhysicsManager::getInstance().RegisterCollider(this);
}


Collider::~Collider() {
	PhysicsManager::getInstance().UnregisterCollider(uid);
}

void Collider::Update(std::unordered_map<unsigned int, Collider*>* colliders) {
	
	for (std::pair<unsigned int, Collider*> pair : (*colliders)) {
		if (pair.second == this) continue;
		if (pair.second->position->x < this->position->x + this->size.x + 1
			&& pair.second->position->x + pair.second->size.x > this->position->x - 1
			&& pair.second->position->y < this->position->y + this->size.y + 1
			&& pair.second->position->y + pair.second->size.y > this->position->y - 1) {
			entity->OnCollisionTouch(pair.second);
		}
	}

}
