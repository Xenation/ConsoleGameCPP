#pragma once
#include <Windows.h>
#include "MathStructs.h"
#include "Constants.h"
class Graphic;
class GraphicRender;
class Collider;
class Camera;
class Entity {
public:
	unsigned int uid = 0;
	Vec2i position;
	Graphic* graphic;
	GraphicRender* graphicRender;
	Collider* collider;
	Entity(Graphic* graphic, Vec2i pos, bool hasCollider = false);
	~Entity();
	virtual void Update();
	virtual void OnCollisionTouch(Collider* touched, Side side);
private:
	Entity();
	Entity(Entity const&);
	void operator=(Entity const&);
};

