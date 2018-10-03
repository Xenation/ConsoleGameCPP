#pragma once

#include <array>

class PlayerState
{
public:
	virtual ~PlayerState() {}
	//virtual void handleInput(class Player& player, int input) {}
	virtual void enter(class Player& player) {}
	virtual void handleInput(Player& player, const std::array<bool, 4> &input) {}
	virtual void update(Player& player) {}

public:
	static class StandingState standing; // Class for forward declaration
	static class RunningRightState runningRight;
	static class RunningLeftState runningLeft;
	static class JumpingState jumping;

	// static class AnimationHolder animations;
};