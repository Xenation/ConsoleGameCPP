#pragma once
class PlatformGenerator;
#include "MathStructs.h"
#include "Entity.h"
class Camera : public Entity {
public:
	Entity* followed;
	Camera(Vec2i pos, int width, int height);
	~Camera();
	bool hasStarted;
	inline Box getBoundingBox() { return {position, {width, height}}; }
	Vec2i getPosition();
	Vec2i getSize();
	short getWidth();
	short getHeight();
	void reset();
	void setPlatformGenerator(PlatformGenerator* platformGeneratorPointer);
	void initializeFreezePosition();
	void initializeSpeedUpPosition();
	virtual void Update();
	void setSpeedFactor(int factor);
	int getSpeedFactor();
private:
	short width;
	short height;
	float elapsedTime;
	int freezeXPosition;
	int speedUpXPosition;
	bool isFrozen;
	float elapsedFreezeTime;
	int speedFactor;
	PlatformGenerator* platformGenerator;
};