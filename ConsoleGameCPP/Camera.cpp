#include "stdafx.h"

#include "Camera.h"
#include "Time.h"
#include "PlatformGenerator.h"
#include "Player.h"


Camera::Camera(Vec2i pos, int width, int height) : Entity::Entity(nullptr, pos, false) {
	this->width = width;
	this->height = height;
	elapsedTime = 0.0f;
	hasStarted = false;
	isFrozen = false;
	elapsedFreezeTime = 0.0f;
	speedFactor = 1;
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
	initializeSpeedUpPosition();
	// Reset the camera position
	position.x = 0;
	setCameraAndPlayerSpeedFactor(1);
}

void Camera::setPlatformGenerator(PlatformGenerator* platformGeneratorPointer) {
	this->platformGenerator = platformGeneratorPointer;
}

void Camera::initializeFreezePosition() {
	freezeXPosition = platformGenerator->getPlayerFreezeXPosition();
}

void Camera::initializeSpeedUpPosition() {
	speedUpXPosition = platformGenerator->getPlayerSpeedUpXPosition();
}

void Camera::initializeEndPosition() {
	endXPosition = platformGenerator->getPlayerEndXPosition();
}

void Camera::Update() {
	//if (followed != nullptr) {
	//	position.x = followed->position.x - width / 2;
	//}

	// Freeze check
	// TODO : Change -1
	// TODO : Have a ref to the player ? We need to change the player speed when we speed up (instead of changing the speed on "enter") : new state function to call ? event ?
	if (position.x == freezeXPosition) {
		isFrozen = true;
		freezeXPosition = -1; // Reset to an impossible value for the camera so that the freeze never launches again
	}
	else if (position.x == speedUpXPosition) {
		setCameraAndPlayerSpeedFactor(2);
		speedUpXPosition = -1; // Reset to an impossible value for the camera so that the freeze never launches again
	}
	else if (position.x >= endXPosition) {
		// Generate title screen
		ImageASCII *img = new ImageASCII();
		if (img->genererImage("end_final.txt")) {
			img->parcourirTableau(img->getImage());
		}
		endXPosition = 99999; // TODO : Change this
	}

	// Start timer before the Camera begins to move
	if (hasStarted) {
		if (isFrozen) {
			elapsedFreezeTime += Time::getDeltaTime() / 1000;

			if (elapsedFreezeTime >= 6.5f)
			{
				isFrozen = false;
				elapsedFreezeTime = 0.0f;
			}
		}
		else {
			position.x += 1 * speedFactor;
		}
	}
}

void Camera::setCameraAndPlayerSpeedFactor(int factor) {
	speedFactor = factor;
	Player* player = dynamic_cast<Player*>(followed);
	player->setSpeedFactor(speedFactor);
	player->updateSpeed();
}
