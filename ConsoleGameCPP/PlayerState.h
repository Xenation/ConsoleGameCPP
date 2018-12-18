#pragma once
#include <array>

/*
===============================================================================
Class used as a basis for the states of the player state machine
===============================================================================
*/
class PlayerState
{
public:
	virtual ~PlayerState() {}

	// Actions to conduct when first entering the state
	virtual void Enter(class Player& player) {}

	// Actions to conduct when input is processed
	virtual void HandleInput(Player& player, const std::array<bool, 7> &input) {}

	// Actions to conduct each update when in the selected state
	virtual void Update(Player& player) {}

	// Update the speed, needed for the last "Speed Up" segment at the end of the game
	virtual void UpdateSpeed(Player& player) {}

public:
	// Static instances of each state of the player state machine
	static class StandingState standing;
	static class RunningRightState runningRight;
	static class RunningLeftState runningLeft;
	static class JumpingState jumping;
};