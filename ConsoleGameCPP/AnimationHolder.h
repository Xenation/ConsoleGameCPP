#pragma once
// Forward declarations
class Graphic;
class Entity;

/*
===============================================================================
Class that holds all the animations of the character
===============================================================================
*/
class AnimationHolder
{
public:

public:
	// Singleton implementation with C++11 compiler : initializer for a local static variable is only run once
	static AnimationHolder& instance() {
		static AnimationHolder *instance = new AnimationHolder();
		return *instance;
	}

	// Simple accessors and mutators
	Graphic* GetPlayerStandingGraph() const;
	void SetStanding(Entity& entity);
	void SetRunningRight(Entity& entity, int stateIndex);
	void SetRunningLeft(Entity& entity, int stateIndex);

	AnimationHolder();
	~AnimationHolder();

private:
	// Char chains and graphics needed to create all the frames of the animations
	const wchar_t** playerStanding;
	const wchar_t** playerRunningRight[4];
	const wchar_t** playerRunningLeft[4];

	Graphic* playerStandingGraph;
	Graphic* playerRunningRightGraphs[4];
	Graphic* playerRunningLeftGraphs[4];
};

