#pragma once
#include <unordered_map>
class Collider;

/*
===============================================================================
Class that handles physics
===============================================================================
*/
class PhysicsManager {
public:
	// Singleton
	static PhysicsManager& GetInstance() {
		static PhysicsManager instance;
		return instance;
	}
	// Registers a collider to be used in collisions
	unsigned int RegisterCollider(Collider* collider);
	// Unregisters a collider using it's unique id
	void UnregisterCollider(unsigned int uid);
	// Updates the state of all the colliders
	void UpdateAllColliders();
private:
	std::unordered_map<unsigned int, Collider*>* colliders;
	unsigned int currentUID = 0;
	PhysicsManager();
	~PhysicsManager();
	PhysicsManager(PhysicsManager const&);	// Don't Implement
	void operator=(PhysicsManager const&);	// Don't implement
};

