#include "stdafx.h"
#include "StandingState.h"
#include "RunningLeftState.h"
#include "RunningRightState.h"
#include "JumpingState.h"
#include "Player.h"
#include "AnimationHolder.h"

StandingState::StandingState()
{
}


StandingState::~StandingState()
{
}

//void StandingState::handleInput(Player& player, int input) {
//	if (input == 100) { // d key : running right
//		player.assignState(&PlayerState::runningRight);
//		player.addVelocity({ 1, 0 });
//		// TODO : Animation vers la droite
//	}
//	else if (input == 113 || input == 97) { // q key (or a key for qwerty keyboards) : running left
//		player.assignState(&PlayerState::runningLeft);
//		player.addVelocity({ -1, 0 });
//		// TODO : Animation vers la gauche
//	}
//	else if (input == 32) { // space key : jumping
//		player.assignState(&PlayerState::jumping);
//		player.addVelocity({ 0, -1 }); // TODO : gérer jump dans le temps
//		// TODO : Animation de saut à lancer
//	}
//}

void StandingState::enter(Player& player) {
	player.setXVelocity(0);
	AnimationHolder::instance().setStanding(player);
}

void StandingState::handleInput(Player& player, const std::array<bool, 4> &input) {
	if (!player.getIsJumping() && input[3]) { // space key : jumping
		player.assignState(&PlayerState::jumping);
		player.enter();
	}
	else if (input[0] && !player.getIsBlockedRight()) { // d key : running right
		player.assignState(&PlayerState::runningRight);
		player.enter();
	}
	else if ((input[1] || input[2]) && !player.getIsBlockedLeft()) { // q key (or a key for qwerty keyboards) : running left
		player.assignState(&PlayerState::runningLeft);
		player.enter();
	}
}

void StandingState::update(Player& player) {
	// No update needed for the standing state
}

void StandingState::updateSpeed (Player& player) {
	// No update needed for the standing state
}