#pragma once

struct Pos {
	int x;
	int y;
};

enum Side {
	Top,
	Left,
	Right,
	Bottom
};

enum CollisionLayer : unsigned int {
	Default	= 0b00000001,
	Decor	= 0b00000010,
	Ally	= 0b00000100,
	Enemy	= 0b00001000
};
