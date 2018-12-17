#pragma once
#include <unordered_map>
#include "MathStructs.h"
class Entity;
struct CollisionLayer;
class Collider {
public:
	Collider(Entity* entity, Vec2i* pos, Vec2i size);
	~Collider();
	void Update(std::unordered_map<unsigned int, Collider*>* colliders);
	void SetLayer(const CollisionLayer* newLayer); // Simple mutator
	const CollisionLayer* GetLayer(); // Simple accessor
	void SetIsStatic(bool newState);

private:
	unsigned int uid;
	Vec2i* position;
	Vec2i size;
	Entity* entity;
	const CollisionLayer* layer;
	bool isStatic = true;
};

