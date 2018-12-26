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

	// Accessors and mutators
	inline Box GetBoundingBox() const { return {position, {width, height}}; }
	Vec2i GetPosition() const;
	Vec2i GetSize() const;
	short GetWidth() const;
	short GetHeight() const;
	void SetFollowed(Entity* newFollowed);
	void SetHasStarted(bool newState);
	void SetCameraAndPlayerSpeedFactor(int factor);

	// Used for respawn of the character when he dies
	void Reset();

	// Used to initialize the notable positions of the camera in the level
	void InitializeAllPositions(PlatformGenerator *platformGenerator);

	// Update design pattern
	virtual void Update();

private:
	// Properties used to initialize and implement the notable positions and effects of the camera in the level
	PlatformGenerator* platformGenerator;
	int freezeXPosition;
	int speedUpXPosition;
	int endXPosition;
	bool isFrozen;
	float elapsedTime;
	float elapsedFreezeTime;
	int speedFactor;

	// Properties used for the horizontal scrolling
	Entity* followed;
	bool hasStarted;

	// Properties used for the size of the camera view
	short width;
	short height;
};