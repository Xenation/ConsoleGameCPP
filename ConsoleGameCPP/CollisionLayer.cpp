#include "stdafx.h"
#include "CollisionLayer.h"


const CollisionLayer CollisionLayer::Default	= { 0, 0b00000000000000000000000000000001 };
const CollisionLayer CollisionLayer::Decor		= { 1, 0b00000000000000000000000000001100 };
const CollisionLayer CollisionLayer::Player		= { 2, 0b00000000000000000000000000000010 };
const CollisionLayer CollisionLayer::Enemy		= { 3, 0b00000000000000000000000000000010 };
const CollisionLayer CollisionLayer::Trap      = { 1, 0b00000000000000000000000000001100 };
