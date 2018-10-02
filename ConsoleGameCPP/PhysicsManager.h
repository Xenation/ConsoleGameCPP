#pragma once
#include <unordered_map>
#include "Collider.h"
class PhysicsManager {
public:
	static PhysicsManager& getInstance() {
		static PhysicsManager instance;
		return instance;
	}
	unsigned int RegisterCollider(Collider* collider);
	void UnregisterCollider(unsigned int uid);
	void UpdateAllColliders();
private:
	std::unordered_map<unsigned int, Collider*>* colliders;
	unsigned int currentUID = 0;
	PhysicsManager();
	~PhysicsManager();
	PhysicsManager(PhysicsManager const&);	// Don't Implement
	void operator=(PhysicsManager const&);	// Don't implement
};

