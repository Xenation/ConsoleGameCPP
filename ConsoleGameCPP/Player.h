#pragma once
#include <array>
#include "MathStructs.h"
#include "Entity.h"
class Collider;
class Graphic;
class PlatformGenerator;

/*
===============================================================================
Class that handles the player movements, state machine and collisions
===============================================================================
*/
class Player : public Entity {
public:
	Player(Graphic* graphic, Vec2i pos, PlatformGenerator* platformGenerator);
	~Player();

	// Method for the update design pattern
	virtual void Update();

	// Methods for the machine state of the player
	virtual void Enter();
	virtual void HandleInput(const std::array<bool, 7> &input);
	void AssignState(class PlayerState* state);
	void UpdateSpeed();

	// Methods for the management of the movement of the character (also with accessors / mutators)
	void AddVelocity(Vec2i velocity);
	void SetXVelocity(int xVelocity);
	void SetYVelocity(int yVelocity);
	void SetJumpingAndRising(bool isJumpingAndRising); // for jumping management
	bool GetIsJumping();
	void SetSpeedFactor(int factor);
	int GetSpeedFactor();

	// Methods for the management of collisions
	bool GetIsBlockedRight();
	bool GetIsBlockedLeft();
	virtual void OnCollisionTouch(Collider* touched, Side side);

	// Methods for the management of respawn
	void SetRespawnPosition(Vec2i newRespawnPosition);
	void Reset();

private:
	// Property for the state machine
	class PlayerState* state;
	
	// Properties needed to manage the movement of the player
	Vec2i velocity;
	bool isJumping;
	bool isRising;
	bool isFalling;
	float elapsedJumpTime;
	int speedFactor;

	// Properties needed to management the collisions of the player
	bool isBlockedRight;
	bool isBlockedLeft;

	// Property needed for the management of respawn
	PlatformGenerator* platformGenerator;
	Vec2i respawnPosition;
};

