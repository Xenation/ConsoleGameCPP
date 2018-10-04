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

//void RunningRightState::handleInput(Player& player, int input) {
//	if (input == 113 || input == 97) { // q key (or a key for qwerty keyboards) : running left
//		player.assignState(&PlayerState::runningLeft);
//		player.addVelocity({ -2, 0 });
//		// TODO : Animation vers la gauche
//	}
//	else if (input == 32) { // space key : jumping
//		player.assignState(&PlayerState::jumping);
//		player.addVelocity({ 1, -1 });
//		// TODO : Animation de saut à lancer
//	}
//	else { // any other key : no movement
//		player.assignState(&PlayerState::standing);
//		player.resetVelocity();
//		// TODO : Animation standing
//	}
//}

void RunningRightState::enter(Player& player) {
	player.setXVelocity(1);
	elapsedRunningTime = 0.0f;
	AnimationHolder::instance().setRunningRight1(player);
}

void RunningRightState::handleInput(Player& player, const std::array<bool, 4> &input) {
	if (!player.getIsJumping() && input[3]) { // space key : jumping
		player.assignState(&PlayerState::jumping);
		player.enter();
	}
	else if (input[0]) {
		// Do nothing : avoids frequently switching between states
	}
	else if ((input[1] || input[2]) && !player.getIsBlockedRight()) { // q key (or a key for qwerty keyboards) : running left
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

	if (elapsedRunningTime >= 0.4f) {
		AnimationHolder::instance().setRunningRight1(player);
		elapsedRunningTime = 0.0f;
	}
	else if (elapsedRunningTime >= 0.3f) {
		AnimationHolder::instance().setRunningRight4(player);
	}
	else if (elapsedRunningTime >= 0.2f) {
		AnimationHolder::instance().setRunningRight3(player);
	}
	else if (elapsedRunningTime >= 0.1f) {
		AnimationHolder::instance().setRunningRight2(player);
	}
}
