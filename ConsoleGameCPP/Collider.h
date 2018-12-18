#pragma once
#include <unordered_map>
#include "MathStructs.h"
class Entity;
struct CollisionLayer;

/*
===============================================================================
Class that manages the collisions
===============================================================================
*/
class Collider {
public:
	Collider(Entity* entity, Vec2i* pos, Vec2i size);
	~Collider();

	// Accessors and mutators
	const CollisionLayer* GetLayer() const;
	void SetLayer(const CollisionLayer* newLayer);
	void SetIsStatic(bool newState);

	// Update design pattern
	void Update(std::unordered_map<unsigned int, Collider*>* colliders);

private:
	unsigned int uid;
	Vec2i* position; // Position of the collider
	Vec2i size; // Size of the collider
	Entity* entity; // Entity associated to the collider
	const CollisionLayer* layer; // Layer of the collider
	bool isStatic = true; // Static colliders do not collide between them
};

