#pragma once
#include "PlayerState.h"
class RunningLeftState :
	public PlayerState
{
public:
	RunningLeftState();
	~RunningLeftState();
	//virtual void handleInput(Player& player, int input);
	virtual void enter(class Player& player);
	virtual void handleInput(Player& player, const std::array<bool, 4> &input);
	virtual void update(Player& player);
	virtual void updateSpeed(Player& player);

private:
	float elapsedRunningLeftTime;
};

