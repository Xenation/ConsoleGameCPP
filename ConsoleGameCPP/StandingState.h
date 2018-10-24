#pragma once
#include "PlayerState.h"
class StandingState :
	public PlayerState
{
public:
	StandingState();
	~StandingState();
	//virtual void handleInput(Player& player, int input);
	virtual void enter(class Player& player);
	virtual void handleInput(Player& player, const std::array<bool, 7> &input);
	virtual void update(Player& player);
	virtual void updateSpeed(Player& player);
};

