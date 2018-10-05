#include "stdafx.h"

#include "PhysicsManager.h"

#include "Collider.h"


PhysicsManager::PhysicsManager() {
	colliders = new std::unordered_map<unsigned int, Collider*>();
}


PhysicsManager::~PhysicsManager() {
	delete colliders;
}

// Returns a unique ID for the collider
unsigned int PhysicsManager::RegisterCollider(Collider* collider) {
	(*colliders)[currentUID] = collider;
	return currentUID++;
}

void PhysicsManager::UnregisterCollider(unsigned int uid) {
	colliders->erase(uid);
}

void PhysicsManager::UpdateAllColliders() {
	for (std::pair<unsigned int, Collider*> pair : (*colliders)) {
		pair.second->Update(colliders);
	}
}
