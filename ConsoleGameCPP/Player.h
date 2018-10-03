#pragma once

#include "Entity.h"
#include <array>

class Player : public Entity {
public:
	Player(Graphic* graphic, Vec2i pos);
	~Player();
	virtual void Update();
	//virtual void handleInput(int input);
	virtual void enter();
	virtual void handleInput(const std::array<bool, 4> &input);
	void assignState(class PlayerState* state);
	void addVelocity(Vec2i velocity);
	void setXVelocity(int xVelocity);
	void setYVelocity(int yVelocity);
	void setJumpingAndRising(bool isJumpingAndRising);
	bool getIsJumping();
private:
	Vec2i velocity;
	class PlayerState* state;
	bool isJumping;
	bool isRising;
	float elapsedJumpTime;
	//bool isStanding;
	//bool isJumping;
	//bool isRunning;
};

