#include "stdafx.h"
#include "MathStructs.h"

int abs(int a) {
	return (a < 0) ? -a : a;
}

bool overlapBox(Box b1, Box b2) {
	return !(b1.pos.x > b2.pos.x + b2.size.x - 1
		|| b1.pos.x + b1.size.x - 1 < b2.pos.x
		|| b1.pos.y > b2.pos.y + b2.size.y
		|| b1.pos.y + b1.size.y - 1 < b2.pos.y);
}

bool isInBox(Box box, Vec2i pos) {
	return pos.x < box.pos.x + box.size.x
		&& pos.x >= box.pos.x
		&& pos.y < box.pos.y + box.size.y
		&& pos.y >= box.pos.y;
}
