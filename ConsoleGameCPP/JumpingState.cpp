#include "stdafx.h"
#include "JumpingState.h"
#include "RunningRightState.h"
#include "RunningLeftState.h"
#include "Time.h"
#include "Player.h"

JumpingState::JumpingState()
{
}


JumpingState::~JumpingState()
{
}

//void JumpingState::handleInput(Player& player, int input) {
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
//}

void JumpingState::enter(Player& player) {
	updateSpeed(player);
	player.setJumpingAndRising(true); // Launches jumping animation
}

void JumpingState::handleInput(class Player& player, const std::array<bool, 7> &input) {
	if ((input[D] || input[RIGHT_ARROW]) && !player.getIsBlockedRight()) { // Running right
		player.assignState(&PlayerState::runningRight);
		player.enter();
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.getIsBlockedLeft()) { // Running left
		player.assignState(&PlayerState::runningLeft);
		player.enter();
	}
}

void JumpingState::update(Player& player) {

}

void JumpingState::updateSpeed(Player& player) {
	// player.setYVelocity(-1 * player.getSpeedFactor());
	// TODO : check if we need to multiply speed for jump (collision troubles...)
	player.setYVelocity(-1);
}
