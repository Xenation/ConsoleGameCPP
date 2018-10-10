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
	void reset();
	void setFreeze(float totalTime);
	virtual void Update();
private:
	short width;
	short height;
	float elapsedTime;
	bool hasStarted;
	bool isFrozen;
	float elapsedFreezeTime;
	float totalFreezeTime;
};