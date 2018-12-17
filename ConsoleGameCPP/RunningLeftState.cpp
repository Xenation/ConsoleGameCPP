#include "stdafx.h"
#include "RunningLeftState.h"
#include "RunningRightState.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "Player.h"
#include "AnimationHolder.h"
#include "Time.h"

RunningLeftState::RunningLeftState()
{
}


RunningLeftState::~RunningLeftState()
{
}

void RunningLeftState::enter(Player& player) {
	updateSpeed(player);
	elapsedRunningLeftTime = 0.0f;
	AnimationHolder::instance().SetRunningLeft(player, 0);
}

void RunningLeftState::handleInput(Player& player, const std::array<bool, 7> &input) {
	if (input[SPACE] && !player.getIsJumping()) { // Jumping
		player.assignState(&PlayerState::jumping);
		player.enter();
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.getIsBlockedLeft()) { // Running left
		// Do nothing : avoids frequently switching between states
	}
	else if ((input[D] || input[RIGHT_ARROW]) && !player.getIsBlockedRight()) { // Running right
		player.assignState(&PlayerState::runningRight);
		player.enter();
	}
	else { // any other key : no movement
		player.assignState(&PlayerState::standing);
		player.enter();
	}
}


void RunningLeftState::update(Player& player) {
	elapsedRunningLeftTime += Time::getInstance().deltaTime / 1000;

	if (elapsedRunningLeftTime >= 0.4f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 0);
		elapsedRunningLeftTime = 0.0f;
	}
	else if (elapsedRunningLeftTime >= 0.3f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 3);
	}
	else if (elapsedRunningLeftTime >= 0.2f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 2);
	}
	else if (elapsedRunningLeftTime >= 0.1f / player.getSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 1);
	}
}

void RunningLeftState::updateSpeed(Player& player) {
	player.setXVelocity(-1 * player.getSpeedFactor());
}
