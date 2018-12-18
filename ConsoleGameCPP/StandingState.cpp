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

void StandingState::Enter(Player& player) {
	player.SetXVelocity(0);
	AnimationHolder::instance().SetStanding(player);
}

void StandingState::HandleInput(Player& player, const std::array<bool, 7> &input) {
	if (input[SPACE] && !player.GetIsJumping()) { // Jumping
		player.AssignState(&PlayerState::jumping);
		player.Enter();
	}
	else if ((input[D] || input[RIGHT_ARROW]) && !player.GetIsBlockedRight()) { // Running right
		player.AssignState(&PlayerState::runningRight);
		player.Enter();
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.GetIsBlockedLeft()) { // Running left
		player.AssignState(&PlayerState::runningLeft);
		player.Enter();
	}
}

void StandingState::Update(Player& player) {
	// No update needed for the standing state
}

void StandingState::UpdateSpeed (Player& player) {
	// No update needed for the standing state
}