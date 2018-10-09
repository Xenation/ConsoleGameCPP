#include "stdafx.h"

#include "Camera.h"
#include "Time.h"


Camera::Camera(Vec2i pos, int width, int height) : Entity::Entity(nullptr, pos, false) {
	this->width = width;
	this->height = height;
	elapsedTime = 0.0f;
	hasStarted = false;
}


Camera::~Camera() {
}

Vec2i Camera::getPosition() {
	return position;
}

Vec2i Camera::getSize() {
	return {width, height};
}

short Camera::getWidth() {
	return width;
}

short Camera::getHeight() {
	return height;
}

void Camera::Update() {
	//if (followed != nullptr) {
	//	position.x = followed->position.x - width / 2;
	//}

	if (!hasStarted)
	{
		elapsedTime += Time::getDeltaTime() / 1000;

		if (elapsedTime >= 2.0f)
		{
			hasStarted = true;
		}
	}
	else
	{
		position.x += 1;
	}
}
