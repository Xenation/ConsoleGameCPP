#pragma once
#include <Windows.h>
#include "MathStructs.h"
#include "Constants.h"
class Graphic;
class GraphicRender;
class Collider;
class Camera;

/*
===============================================================================
Base class for all entities of the game
===============================================================================
*/
class Entity {
public:
	Entity(Graphic* graphic, Vec2i pos, bool hasCollider = false);
	~Entity();

	// Update design pattern
	virtual void Update();

	// Method for collisions
	virtual void OnCollisionTouch(Collider* touched, Side side);

	// Accessors and mutators
	void SetGraphic(Graphic* newGraphic);
	Graphic* GetGraphic() const;
	Vec2i GetPosition() const;
	Collider* GetCollider() const;
	GraphicRender* GetGraphicRender() const;

private:
	Entity();
	Entity(Entity const&);
	void operator=(Entity const&);
	unsigned int uid = 0;
	Graphic* graphic;

protected:
	Vec2i position;
	GraphicRender* graphicRender;
	Collider* collider;
};

