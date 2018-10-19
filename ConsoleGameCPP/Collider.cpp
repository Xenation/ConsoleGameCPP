#include "stdafx.h"

#include "Collider.h"

#include "CollisionLayer.h"
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
	if (isStatic) return;

	for (std::pair<unsigned int, Collider*> pair : (*colliders)) {
		if (pair.second == this || !((1 << pair.second->layer->layerIndex) & this->layer->layerMask)) continue;

		Collider* leftMost;
		Collider* rightMost;
		if (pair.second->position->x < this->position->x) {
			leftMost = pair.second;
			rightMost = this;
		}
		else {
			leftMost = this;
			rightMost = pair.second;
		}
		Collider* topMost;
		Collider* bottomMost;
		if (pair.second->position->y < this->position->y) {
			topMost = pair.second;
			bottomMost = this;
		}
		else {
			topMost = this;
			bottomMost = pair.second;
		}

		if (leftMost->size.x == rightMost->position->x - leftMost->position->x
			&& topMost->size.y > bottomMost->position->y - topMost->position->y) { // Left/Right side touch
			if (leftMost == this) { // Right
				entity->OnCollisionTouch(pair.second, Side::Right);
			}
			else { // Left
				entity->OnCollisionTouch(pair.second, Side::Left);
			}
		}
		if (leftMost->size.x > rightMost->position->x - leftMost->position->x
			&& topMost->size.y == bottomMost->position->y - topMost->position->y) { // Bottom/Top side touch
			if (topMost == this) { // Bottom
				entity->OnCollisionTouch(pair.second, Side::Bottom);
			}
			else { // Top
				entity->OnCollisionTouch(pair.second, Side::Top);
			}
		}

	}

}
