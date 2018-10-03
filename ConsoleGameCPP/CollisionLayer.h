#pragma once
struct CollisionLayer {
public:
	const unsigned int layerIndex;
	const unsigned int layerMask;
	static const CollisionLayer Default;
	static const CollisionLayer Decor;
	static const CollisionLayer Player;
	static const CollisionLayer Enemy;
};

