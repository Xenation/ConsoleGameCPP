#pragma once
#include "PlayerState.h"

/*
===============================================================================
Standing still - State of the player state machine
===============================================================================
*/
class StandingState :
	public PlayerState
{
public:
	StandingState();
	~StandingState();

	// Implementation of the state methods
	virtual void Enter(class Player& player);
	virtual void HandleInput(Player& player, const std::array<bool, 7> &input);
	virtual void Update(Player& player);
	virtual void UpdateSpeed(Player& player);
};

