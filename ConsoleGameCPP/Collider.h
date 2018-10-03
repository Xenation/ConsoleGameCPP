#pragma once
#include <unordered_map>
#include "MathStructs.h"
#include "CollisionLayer.h"

class Entity;
class Collider {
public:
	Entity* entity;
	const CollisionLayer* layer;
	Collider(Entity* entity, Pos* pos, Pos size);
	~Collider();
	void Update(std::unordered_map<unsigned int, Collider*>* colliders);
private:
	unsigned int uid;
	Pos* position;
	Pos size;
};

