#pragma once
#include "MathStructs.h"
class Camera {
public:
	Camera(Vec2i pos, int width, int height);
	~Camera();
private:
	int width;
	int height;
	Vec2i position;
};

