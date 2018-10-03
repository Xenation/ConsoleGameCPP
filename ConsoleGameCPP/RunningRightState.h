#pragma once
#include "PlayerState.h"
class RunningRightState :
	public PlayerState
{
public:
	RunningRightState();
	~RunningRightState();
	//virtual void handleInput(Player& player, int input);
	virtual void enter(class Player& player);
	virtual void handleInput(Player& player, const std::array<bool, 4> &input);
	virtual void update(Player& player);

private:
	float elapsedRunningTime;
};
