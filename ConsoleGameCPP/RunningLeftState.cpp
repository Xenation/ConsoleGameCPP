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

void RunningLeftState::Enter(Player& player) {
	UpdateSpeed(player);
	elapsedRunningLeftTime = 0.0f;
	AnimationHolder::instance().SetRunningLeft(player, 0);
}

void RunningLeftState::HandleInput(Player& player, const std::array<bool, 7> &input) {
	if (input[SPACE] && !player.GetIsJumping()) { // Jumping
		player.AssignState(&PlayerState::jumping);
		player.Enter();
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.GetIsBlockedLeft()) { // Running left
		// Do nothing : avoids frequently switching between states
	}
	else if ((input[D] || input[RIGHT_ARROW]) && !player.GetIsBlockedRight()) { // Running right
		player.AssignState(&PlayerState::runningRight);
		player.Enter();
	}
	else { // any other key : no movement
		player.AssignState(&PlayerState::standing);
		player.Enter();
	}
}


void RunningLeftState::Update(Player& player) {
	elapsedRunningLeftTime += Time::GetInstance().GetDeltaTime() / 1000;

	if (elapsedRunningLeftTime >= 0.4f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 0);
		elapsedRunningLeftTime = 0.0f;
	}
	else if (elapsedRunningLeftTime >= 0.3f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 3);
	}
	else if (elapsedRunningLeftTime >= 0.2f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 2);
	}
	else if (elapsedRunningLeftTime >= 0.1f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningLeft(player, 1);
	}
}

void RunningLeftState::UpdateSpeed(Player& player) {
	player.SetXVelocity(-1 * player.GetSpeedFactor());
}
