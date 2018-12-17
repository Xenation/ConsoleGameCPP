#pragma once
class PlatformGenerator;
#include "MathStructs.h"
#include "Entity.h"

/*
===============================================================================
Class that manages the camera and the related effects during play
===============================================================================
*/
class Camera : public Entity {
public:
	Camera(Vec2i pos, int width, int height);
	~Camera();
	inline Box GetBoundingBox() { return {position, {width, height}}; }
	Vec2i GetPosition();
	Vec2i GetSize();
	short GetWidth();
	short GetHeight();
	void Reset();
	void SetPlatformGenerator(PlatformGenerator* platformGeneratorPointer);
	void InitializeFreezePosition();
	void InitializeSpeedUpPosition();
	void InitializeEndPosition();
	virtual void Update();
	void SetCameraAndPlayerSpeedFactor(int factor);
	void SetFollowed(Entity* newFollowed);
	void SetHasStarted(bool newState);

private:
	Entity* followed;
	bool hasStarted;
	short width;
	short height;
	float elapsedTime;
	int freezeXPosition;
	int speedUpXPosition;
	int endXPosition;
	bool isFrozen;
	float elapsedFreezeTime;
	int speedFactor;
	PlatformGenerator* platformGenerator;
};