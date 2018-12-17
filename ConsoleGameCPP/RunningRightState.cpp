#include "stdafx.h"
#include "RunningRightState.h"
#include "RunningLeftState.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "Player.h"
#include "AnimationHolder.h"
#include "Time.h"

RunningRightState::RunningRightState()
{
}


RunningRightState::~RunningRightState()
{
}

void RunningRightState::enter(Player& player) {
	updateSpeed(player);
	elapsedRunningTime = 0.0f;
	AnimationHolder::instance().SetRunningRight(player, 0);
}

void RunningRightState::handleInput(Player& player, const std::array<bool, 7> &input) {
	if (input[SPACE] && !player.getIsJumping()) { // Jumping
		player.assignState(&PlayerState::jumping);
		player.enter();
	}
	else if (input[D] || input[RIGHT_ARROW]) {
		// Do nothing : avoids frequently switching between states
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.getIsBlockedRight()) { // Running left
		player.assignState(&PlayerState::runningLeft);
		player.enter();
	}
	else { // any other key : no movement
		player.assignState(&PlayerState::standing);
		player.enter();
	}
}

void RunningRightState::update(Player& player) {
	elapsedRunningTime += Time::getInstance().deltaTime / 1000;

	if (elapsedRunningTime >= 0.4f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 0);
		elapsedRunningTime = 0.0f;
	}
	else if (elapsedRunningTime >= 0.3f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 3);
	}
	else if (elapsedRunningTime >= 0.2f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 2);
	}
	else if (elapsedRunningTime >= 0.1f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 1);
	}
}

void RunningRightState::updateSpeed(Player& player) {
	player.setXVelocity(1 * player.getSpeedFactor());
}
