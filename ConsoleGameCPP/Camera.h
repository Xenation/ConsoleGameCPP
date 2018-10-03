#pragma once
#include "MathStructs.h"
class Camera {
public:
	Camera(Vec2i pos, int width, int height);
	~Camera();
	Box getBoundingBox();
	Vec2i getPosition();
	Vec2i getSize();
	short getWidth();
	short getHeight();
	void Update();
private:
	Vec2i position;
	short width;
	short height;
};

