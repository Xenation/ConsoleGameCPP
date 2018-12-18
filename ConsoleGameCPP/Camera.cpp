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

Vec2i Camera::GetPosition() const {
	return position;
}

Vec2i Camera::GetSize() const {
	return {width, height};
}

short Camera::GetWidth() const {
	return width;
}

short Camera::GetHeight() const {
	return height;
}

void Camera::Reset() {
	// Reset the initial timer
	hasStarted = false;
	// Reset the freeze settings
	isFrozen = false;
	elapsedFreezeTime = 0.0f;
	InitializeFreezePosition();
	InitializeSpeedUpPosition();
	// Reset the camera position
	position.x = 0;
	SetCameraAndPlayerSpeedFactor(1);
}

void Camera::SetPlatformGenerator(PlatformGenerator* platformGeneratorPointer) {
	this->platformGenerator = platformGeneratorPointer;
}

void Camera::InitializeFreezePosition() {
	freezeXPosition = platformGenerator->GetPlayerFreezeXPosition();
}

void Camera::InitializeSpeedUpPosition() {
	speedUpXPosition = platformGenerator->GetPlayerSpeedUpXPosition();
}

void Camera::InitializeEndPosition() {
	endXPosition = platformGenerator->GetPlayerEndXPosition();
}

void Camera::Update() {
	//if (followed != nullptr) {
	//	position.x = followed->position.x - width / 2;
	//}

	// Freeze check
	if (position.x == freezeXPosition) {
		isFrozen = true;
		freezeXPosition = -1; // Reset to an impossible value for the camera so that the freeze never launches again
	}
	else if (position.x == speedUpXPosition) {
		SetCameraAndPlayerSpeedFactor(2);
		speedUpXPosition = -1; // Reset to an impossible value for the camera so that the freeze never launches again
	}
	else if (position.x >= endXPosition) {
		// Generate end screen
		ImageASCII *img = new ImageASCII();
		if (img->GenerateImage("end_final.txt")) {
			img->SweepTable(img->GetImage());
		}
		endXPosition = 99999; // TODO : Change this
	}

	// Start timer before the Camera begins to move
	if (hasStarted) {
		if (isFrozen) {
			elapsedFreezeTime += Time::GetDeltaTime() / 1000;

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

void Camera::SetCameraAndPlayerSpeedFactor(int factor) {
	speedFactor = factor;
	Player* player = dynamic_cast<Player*>(followed);
	player->SetSpeedFactor(speedFactor);
	player->UpdateSpeed();
}

void Camera::SetFollowed(Entity* newFollowed) {
	this->followed = newFollowed;
}

void Camera::SetHasStarted(bool newState) {
	this->hasStarted = newState;
}
