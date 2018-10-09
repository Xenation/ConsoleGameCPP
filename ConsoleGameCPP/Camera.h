#pragma once
#include "MathStructs.h"
#include "Entity.h"
class Camera : public Entity {
public:
	Entity* followed;
	Camera(Vec2i pos, int width, int height);
	~Camera();
	inline Box getBoundingBox() { return {position, {width, height}}; }
	Vec2i getPosition();
	Vec2i getSize();
	short getWidth();
	short getHeight();
	void Reset();
	virtual void Update();
private:
	short width;
	short height;
	float elapsedTime;
	bool hasStarted;
};