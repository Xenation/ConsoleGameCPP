#pragma once
#include "PlayerState.h"

/*
===============================================================================
Running to the left - State of the player state machine
===============================================================================
*/
class RunningLeftState :
	public PlayerState
{
public:
	RunningLeftState();
	~RunningLeftState();
	
	// Implementation of the state methods
	virtual void Enter(class Player& player);
	virtual void HandleInput(Player& player, const std::array<bool, 7> &input);
	virtual void Update(Player& player);
	virtual void UpdateSpeed(Player& player);

private:
	float elapsedRunningLeftTime;
};

