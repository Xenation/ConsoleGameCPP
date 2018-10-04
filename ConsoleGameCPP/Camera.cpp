#include "stdafx.h"
#include "Camera.h"


Camera::Camera(Vec2i pos, int width, int height) : Entity::Entity(nullptr, pos, false) {
	this->width = width;
	this->height = height;
}


Camera::~Camera() {
}

Box Camera::getBoundingBox() {
	return { position, {width, height} };
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
	
}
