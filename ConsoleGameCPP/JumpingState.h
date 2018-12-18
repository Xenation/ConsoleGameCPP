#pragma once
#include "PlayerState.h"

/*
===============================================================================
Class part of the character state machine : jumping action
===============================================================================
*/
class JumpingState : public PlayerState {
public:
	JumpingState();
	~JumpingState();

	// Implementation of the player state methods
	virtual void Enter(class Player& player);
	virtual void HandleInput(Player& player, const std::array<bool, 7> &input);
	virtual void Update(Player& player);
	virtual void UpdateSpeed(Player& player);
};

