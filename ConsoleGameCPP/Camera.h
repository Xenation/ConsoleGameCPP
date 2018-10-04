#pragma once
#include "MathStructs.h"
#include "Entity.h"
class Camera : public Entity {
public:
	Entity* followed;
	Camera(Vec2i pos, int width, int height);
	~Camera();
	Box getBoundingBox();
	Vec2i getPosition();
	Vec2i getSize();
	short getWidth();
	short getHeight();
	virtual void Update();
private:
	short width;
	short height;
};