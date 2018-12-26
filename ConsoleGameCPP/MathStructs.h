#pragma once

/*
===============================================================================
Defines a 2D Vector of integers
===============================================================================
*/
struct Vec2i {
	// The x component
	int x;
	// The y component
	int y;
public:
	Vec2i operator+(Vec2i other) {
		return {this->x + other.x, this->y + other.y};
	}
	Vec2i  operator-(Vec2i other) {
		return {this->x - other.x, this->y - other.y};
	}
	void operator+=(Vec2i other) {
		this->x += other.x;
		this->y += other.y;
	}
	void operator-=(Vec2i other) {
		this->x -= other.x;
		this->y -= other.y;
	}
};

/*
===============================================================================
Defines a 2D box by its position and size
===============================================================================
*/
struct Box {
	Vec2i pos;
	Vec2i size;
};

/*
===============================================================================
Enum defining a side (Top, Left, Right, Bottom)
===============================================================================
*/
enum Side {
	Top,
	Left,
	Right,
	Bottom
};

// Determines whether two boxes overlap
bool overlapBox(Box b1, Box b2);
// Determines whether the given position is inside the given box
bool isInBox(Box box, Vec2i pos);
