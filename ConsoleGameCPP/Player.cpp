#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "StandingState.h"
#include <array>
#include "Time.h"
#include "PlatformGenerator.h"

Player::Player(Graphic* graphic, Vec2i pos, PlatformGenerator* platformGenerator) : Entity::Entity(graphic, pos, true) {
	this->velocity = { 0, 0 }; // No velocity at first
	assignState(&PlayerState::standing);
	isJumping = false;
	isRising = false;
	isFalling = false;
	isBlockedRight = false;
	isBlockedLeft = false;
	elapsedJumpTime = 0.0f;
	this->collider->layer = &CollisionLayer::Player;
	this->platformGenerator = platformGenerator;
	//isStanding = true; // Starts standing
	//isRunning = false;
	//isJumping = false;
}


Player::~Player() {

}

void Player::Update() {
	
	if (isJumping) {
		if (isRising) {
			elapsedJumpTime += Time::getInstance().deltaTime / 1000;

			if (elapsedJumpTime >= 0.3f) {
				setYVelocity(1);
				isRising = false;
				elapsedJumpTime = 0.0f;
			}
			//else if (elapsedJumpTime >= 0.4f)
			//{
			//	setYVelocity(0);
			//}
		}
	}
	else {
		if (isFalling) {
			setYVelocity(1);
		}
		elapsedJumpTime = 0.0f; // Resets the jump timer in case the full jump is interrupted by a platform
	}

	state->update(*this);
	position.x += velocity.x;
	position.y += velocity.y;

	// Kill check
	if (position.y >= SCREEN_HEIGHT) {
		Vec2i initialPosition = platformGenerator->getPlayerInitialPosition();
		position.x = initialPosition.x;
		position.y = initialPosition.y;
	}

	isFalling = true; // Falling by default, colliders will then change the status if there is something underneath the player
	isBlockedRight = false;
	isBlockedLeft = false;
}

void Player::enter() {
	state->enter(*this);
}

void Player::handleInput(const std::array<bool, 4> &input) {
	state->handleInput(*this, input);
}

void Player::assignState(PlayerState* state) {
	this->state = state;
}

void Player::addVelocity(Vec2i velocity) {
	this->velocity = { this->velocity.x + velocity.x, this->velocity.y + velocity.y };
}

void Player::setXVelocity(int xVelocity) {
	this->velocity.x = xVelocity;
}

void Player::setYVelocity(int yVelocity) {
	this->velocity.y = yVelocity;
}

void Player::setJumpingAndRising(bool isJumpingAndRising) {
	this->isJumping = isJumpingAndRising;
	this->isRising = isJumpingAndRising;
}

bool Player::getIsJumping() {
	return isJumping;
}

bool Player::getIsBlockedRight() {
	return isBlockedRight;
}

bool Player::getIsBlockedLeft() {
	return isBlockedLeft;
}

void Player::OnCollisionTouch(Collider* touched, Side side) {
	
	if (touched->layer == &CollisionLayer::Enemy)
	{
		// TODO : Kill player : reset via GameManager
	}
	else if (side == Side::Bottom) {
		isFalling = false;
		setYVelocity(0);
		if (isJumping) {
			isJumping = false;
			assignState(&PlayerState::standing);
			enter();
		}
	}
	else if (side == Side::Left) {
		isBlockedLeft = true;
		setXVelocity(0);
	}
	else if (side == Side::Right) {
		isBlockedRight = true;
		setXVelocity(0);
	}
	else if (side == Side::Top) {
		setYVelocity(-this->velocity.y);
	}
}