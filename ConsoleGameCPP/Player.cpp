#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "StandingState.h"
#include <array>
#include "Time.h"

Player::Player(Graphic* graphic, Vec2i pos) : Entity::Entity(graphic, pos) {
	this->velocity = { 0, 0 }; // No velocity at first
	assignState(&PlayerState::standing);
	isJumping = false;
	isRising = false;
	elapsedJumpTime = 0.0f;
	//isStanding = true; // Starts standing
	//isRunning = false;
	//isJumping = false;
}


Player::~Player() {

}

void Player::Update() {
	if (isJumping) {
		if (isRising) {
			elapsedJumpTime += Time::getInstance().deltaTime / 1000; // TODO : récupérer le vrai temps écoulé ?

			if (elapsedJumpTime >= 0.8f) {
				setYVelocity(2);
				isRising = false;
				elapsedJumpTime = 0.0f;
			}
			else if (elapsedJumpTime >= 0.4f)
			{
				setYVelocity(1);
			}
			else if (elapsedJumpTime >= 0.2f)
			{
				setYVelocity(-1);
			}
		}
	}
	state->update(*this);
	position.x += velocity.x;
	position.y += velocity.y;
}

//void Player::handleInput(int input) {
//	state->handleInput(*this, input);
//}

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
