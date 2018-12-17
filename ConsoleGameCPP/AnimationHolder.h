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
	static AnimationHolder& instance() {
		// Singleton implementation with C++11 compiler : initializer for a local static variable is only run once
		static AnimationHolder *instance = new AnimationHolder();
		return *instance;
	}

	Graphic* GetPlayerStandingGraph(); // Simple accessor
	void SetStanding(Entity& entity); // Simple mutator
	void SetRunningRight(Entity& entity, int stateIndex); // Simple mutator
	void SetRunningLeft(Entity& entity, int stateIndex); // Simple mutator

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

