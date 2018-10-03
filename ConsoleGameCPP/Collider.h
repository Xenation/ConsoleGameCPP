#pragma once
#include <unordered_map>
#include "MathStructs.h"
#include "CollisionLayer.h"

class Entity;
class Collider {
public:
	Entity* entity;
	const CollisionLayer* layer;
	Collider(Entity* entity, Vec2i* pos, Vec2i size);
	~Collider();
	void Update(std::unordered_map<unsigned int, Collider*>* colliders);
private:
	unsigned int uid;
	Vec2i* position;
	Vec2i size;
};

