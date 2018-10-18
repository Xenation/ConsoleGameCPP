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

//void RunningLeftState::handleInput(Player& player, int input) {
//	if (input == 100) { // d key : running right
//		player.assignState(&PlayerState::runningRight);
//		player.addVelocity({ 2, 0 });
//		// TODO : Animation vers la droite
//	}
//	else if (input == 32) { // space key : jumping
//		player.assignState(&PlayerState::jumping);
//		player.addVelocity({ -1, -1 });
//		// TODO : Animation de saut à lancer
//	}
//	else { // any other key : no movement
//		player.assignState(&PlayerState::standing);
//		player.resetVelocity();
//		// TODO : Animation standing
//	}
//}

void RunningLeftState::enter(Player& player) {
	updateSpeed(player);
	elapsedRunningLeftTime = 0.0f;
	AnimationHolder::instance().setRunningLeft1(player);
}

void RunningLeftState::handleInput(Player& player, const std::array<bool, 4> &input) {
	if (input[3] && !player.getIsJumping()) { // space key : jumping
		player.assignState(&PlayerState::jumping);
		player.enter();
	}
	else if ((input[1] || input[2]) && !player.getIsBlockedLeft()) { // q key (or a key for qwerty keyboards) : running left
		// Do nothing : avoids frequently switching between states
	}
	else if (input[0] && !player.getIsBlockedRight()) { // d key : running right
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
		AnimationHolder::instance().setRunningLeft1(player);
		elapsedRunningLeftTime = 0.0f;
	}
	else if (elapsedRunningLeftTime >= 0.3f / player.getSpeedFactor()) {
		AnimationHolder::instance().setRunningLeft4(player);
	}
	else if (elapsedRunningLeftTime >= 0.2f / player.getSpeedFactor()) {
		AnimationHolder::instance().setRunningLeft3(player);
	}
	else if (elapsedRunningLeftTime >= 0.1f / player.getSpeedFactor()) {
		AnimationHolder::instance().setRunningLeft2(player);
	}
}

void RunningLeftState::updateSpeed(Player& player) {
	player.setXVelocity(-1 * player.getSpeedFactor());
}
