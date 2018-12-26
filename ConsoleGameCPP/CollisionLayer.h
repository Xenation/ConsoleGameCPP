#pragma once

/*
===============================================================================
Struct that holds the layers for the collision system
===============================================================================
*/
struct CollisionLayer {
public:
	// The index of this layer
	const unsigned int layerIndex;
	// The mask of interactions with other layers
	const unsigned int layerMask;

	// The layer used by default
	static const CollisionLayer Default;
	// The layer used for the decor
	static const CollisionLayer Decor;
	// The layer used for the player
	static const CollisionLayer Player;
	// The layer used for enemies
	static const CollisionLayer Enemy;
	// The layer used for traps
	static const CollisionLayer Trap;
};

