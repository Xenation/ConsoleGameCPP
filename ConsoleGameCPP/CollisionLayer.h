#pragma once

/*
===============================================================================
Struct that holds the layers for the collision system
===============================================================================
*/
struct CollisionLayer {
public:
	const unsigned int layerIndex;
	const unsigned int layerMask;
	static const CollisionLayer Default;
	static const CollisionLayer Decor;
	static const CollisionLayer Player;
	static const CollisionLayer Enemy;
	static const CollisionLayer Trap;
};

