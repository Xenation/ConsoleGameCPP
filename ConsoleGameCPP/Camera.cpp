#include "stdafx.h"

#include "Camera.h"
#include "Time.h"
#include "PlatformGenerator.h"
#include "Player.h"
#include "Game.h"


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
	InitializeAllPositions(platformGenerator);
	// Reset the camera position
	position.x = 0;
	SetCameraAndPlayerSpeedFactor(1);
}

void Camera::InitializeAllPositions(PlatformGenerator *platformGenerator) {
	this->platformGenerator = platformGenerator;
	freezeXPosition = platformGenerator->GetPlayerFreezeXPosition();
	speedUpXPosition = platformGenerator->GetPlayerSpeedUpXPosition();
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
		Game::SetIsEndReached(true); // Stops the game and launches the end screen
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
