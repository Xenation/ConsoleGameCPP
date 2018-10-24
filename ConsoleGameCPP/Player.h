#pragma once
#include <array>
#include "MathStructs.h"
#include "Entity.h"
class Collider;
class Graphic;
class PlatformGenerator;
class Player : public Entity {
public:
	Player(Graphic* graphic, Vec2i pos, PlatformGenerator* platformGenerator);
	~Player();
	virtual void Update();
	//virtual void handleInput(int input);
	virtual void enter();
	virtual void handleInput(const std::array<bool, 7> &input);
	void assignState(class PlayerState* state);
	void addVelocity(Vec2i velocity);
	void setXVelocity(int xVelocity);
	void setYVelocity(int yVelocity);
	void setJumpingAndRising(bool isJumpingAndRising);
	bool getIsJumping();
	bool getIsBlockedRight();
	bool getIsBlockedLeft();
	virtual void OnCollisionTouch(Collider* touched, Side side);
	void setRespawnPosition(Vec2i newRespawnPosition);
	void reset();
	void setSpeedFactor(int factor);
	int getSpeedFactor();
	void updateSpeed();
private:
	Vec2i velocity;
	class PlayerState* state;
	bool isJumping;
	bool isRising;
	bool isFalling;
	bool isBlockedRight;
	bool isBlockedLeft;
	float elapsedJumpTime;
	PlatformGenerator* platformGenerator;
	Vec2i respawnPosition; // Used to teleport the player in case of death
	int speedFactor;
	//bool isStanding;
	//bool isJumping;
	//bool isRunning;
};

