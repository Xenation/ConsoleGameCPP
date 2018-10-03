#pragma once

struct Vec2i {
	int x;
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

bool overlapBox(Box b1, Box b2);
bool isInBox(Box box, Vec2i pos);
