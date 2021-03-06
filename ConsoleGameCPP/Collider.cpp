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
	this->uid = PhysicsManager::GetInstance().RegisterCollider(this);
}

Collider::~Collider() {
	PhysicsManager::GetInstance().UnregisterCollider(uid);
}

void Collider::Update(std::unordered_map<unsigned int, Collider*>* colliders) { // Collision Checks
	if (isStatic) return; // Static objects do not actively check for collisions

	for (std::pair<unsigned int, Collider*> pair : (*colliders)) { // Loop through all colliders
		if (pair.second == this || !((1 << pair.second->layer->layerIndex) & this->layer->layerMask)) continue; // Avoid the current collider and any collider on a layer that does not interact with the current

		// Simplify checks by ordering left/right and top/bottom
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

		// Check for touch
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

void Collider::SetLayer(const CollisionLayer* newLayer) {
	layer = newLayer;
}

const CollisionLayer* Collider::GetLayer() const {
	return layer;
}

void Collider::SetIsStatic(bool newState) {
	isStatic = newState;
}
