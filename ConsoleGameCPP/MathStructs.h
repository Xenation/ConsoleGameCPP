#pragma once

struct Vec2i {
	int x;
	int y;
};

struct Box {
	Vec2i pos;
	Vec2i size;
};

enum Side {
	Top,
	Left,
	Right,
	Bottom
};
