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

void RunningRightState::Enter(Player& player) {
	UpdateSpeed(player);
	elapsedRunningTime = 0.0f;
	AnimationHolder::instance().SetRunningRight(player, 0);
}

void RunningRightState::HandleInput(Player& player, const std::array<bool, 7> &input) {
	if (input[SPACE] && !player.GetIsJumping()) { // Jumping
		player.AssignState(&PlayerState::jumping);
		player.Enter();
	}
	else if (input[D] || input[RIGHT_ARROW]) {
		// Do nothing : avoids frequently switching between states
	}
	else if ((input[Q] || input[A] || input[LEFT_ARROW]) && !player.GetIsBlockedRight()) { // Running left
		player.AssignState(&PlayerState::runningLeft);
		player.Enter();
	}
	else { // any other key : no movement
		player.AssignState(&PlayerState::standing);
		player.Enter();
	}
}

void RunningRightState::Update(Player& player) {
	elapsedRunningTime += Time::GetInstance().GetDeltaTime() / 1000;

	if (elapsedRunningTime >= 0.4f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 0);
		elapsedRunningTime = 0.0f;
	}
	else if (elapsedRunningTime >= 0.3f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 3);
	}
	else if (elapsedRunningTime >= 0.2f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 2);
	}
	else if (elapsedRunningTime >= 0.1f / player.GetSpeedFactor()) {
		AnimationHolder::instance().SetRunningRight(player, 1);
	}
}

void RunningRightState::UpdateSpeed(Player& player) {
	player.SetXVelocity(1 * player.GetSpeedFactor());
}
