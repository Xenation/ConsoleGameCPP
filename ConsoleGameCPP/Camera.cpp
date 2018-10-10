#include "stdafx.h"

#include "Camera.h"
#include "Time.h"
#include "PlatformGenerator.h"


Camera::Camera(Vec2i pos, int width, int height) : Entity::Entity(nullptr, pos, false) {
	this->width = width;
	this->height = height;
	elapsedTime = 0.0f;
	hasStarted = false;
	isFrozen = false;
	elapsedFreezeTime = 0.0f;
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

void Camera::reset() {
	// Reset the initial timer
	hasStarted = false;
	// Reset the freeze settings
	isFrozen = false;
	elapsedFreezeTime = 0.0f;
	initializeFreezePosition();
	// Reset the camera position
	position.x = 0;
}

void Camera::setPlatformGenerator(PlatformGenerator* platformGeneratorPointer) {
	this->platformGenerator = platformGeneratorPointer;
}

void Camera::initializeFreezePosition() {
	freezeXPosition = platformGenerator->getPlayerFreezeXPosition();
}

void Camera::Update() {
	//if (followed != nullptr) {
	//	position.x = followed->position.x - width / 2;
	//}

	// Freeze check
	if (position.x == freezeXPosition) {
		{
			isFrozen = true;
			freezeXPosition = -1; // Reset to an impossible value for the camera so that the freeze never launches again
		}
	}

	// Start timer before the Camera begins to move
	if (!hasStarted) {
		elapsedTime += Time::getDeltaTime() / 1000;

		if (elapsedTime >= 0.7f)
		{
			hasStarted = true;
			elapsedTime = 0.0f;
		}
	}
	else if (isFrozen) {
		elapsedFreezeTime += Time::getDeltaTime() / 1000;

		if (elapsedFreezeTime >= 15.0f)
		{
			isFrozen = false;
			elapsedFreezeTime = 0.0f;
		}
	}
	else {
		position.x += 1;
	}
}
