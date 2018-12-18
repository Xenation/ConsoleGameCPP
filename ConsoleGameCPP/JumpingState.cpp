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

void JumpingState::Enter(Player& player) {
	UpdateSpeed(player); // Changes the speed
	player.SetJumpingAndRising(true); // Launches jumping animation
}

void JumpingState::HandleInput(class Player& player, const std::array<bool, 7> &input) {
	if ((input[D] || input[RIGHT_ARROW]) && !player.GetIsBlockedRight()) { // Running right
		player.AssignState(&PlayerState::runningRight);
		player.Enter();
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.GetIsBlockedLeft()) { // Running left
		player.AssignState(&PlayerState::runningLeft);
		player.Enter();
	}
}

void JumpingState::Update(Player& player) {

}

void JumpingState::UpdateSpeed(Player& player) {
	player.SetYVelocity(-1);
}
