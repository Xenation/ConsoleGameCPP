#include "stdafx.h"
#include "Camera.h"


Camera::Camera(Vec2i pos, int width, int height) {
	this->position = pos;
	this->width = width;
	this->height = height;
}


Camera::~Camera() {
}
