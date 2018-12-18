#include "stdafx.h"

#include "Player.h"

#include "Constants.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "PlatformGenerator.h"
#include "Collider.h"
#include "CollisionLayer.h"
#include "Time.h"
#include "Game.h"
#include "SoundManager.h"
#include "GraphicRender.h"
#include "RenderLayer.h"
#include "Renderer.h"
#include "Camera.h"


Player::Player(Graphic* graphic, Vec2i pos, PlatformGenerator* platformGenerator) : Entity::Entity(graphic, pos, true) {
	this->velocity = { 0, 0 }; // No velocity at first
	graphicRender->SetLayer(RenderLayer::Player);
	AssignState(&PlayerState::standing);
	isJumping = false;
	isRising = false;
	isFalling = false;
	isBlockedRight = false;
	isBlockedLeft = false;
	elapsedJumpTime = 0.0f;
	this->collider->SetLayer(&CollisionLayer::Player);
	this->collider->SetIsStatic(false);
	SetRespawnPosition(platformGenerator->GetPlayerInitialPosition());
	speedFactor = 1;
	//isStanding = true; // Starts standing
	//isRunning = false;
	//isJumping = false;
}


Player::~Player() {

}

void Player::Update() {

	if (isJumping) {
		if (isRising) {
			elapsedJumpTime += Time::GetInstance().GetDeltaTime() / 1000;

			if (elapsedJumpTime >= 0.3f) {
				SetYVelocity(1);
				isRising = false;
				elapsedJumpTime = 0.0f;
			}
		}
	}
	else {
		if (isFalling) {
			SetYVelocity(1);
		}
		elapsedJumpTime = 0.0f; // Resets the jump timer in case the full jump is interrupted by a platform
	}

	state->Update(*this);
	position.x += velocity.x;
	position.y += velocity.y;

	// Kill check
	if (position.y >= SCREEN_HEIGHT || position.x <= Game::GetRenderer()->GetCamera()->GetPosition().x) {
		Reset();
	}

	isFalling = true; // Falling by default, colliders will then change the status if there is something underneath the player
	isBlockedRight = false;
	isBlockedLeft = false;
}

void Player::Enter() {
	state->Enter(*this);
}

void Player::HandleInput(const std::array<bool, 7> &input) {
	state->HandleInput(*this, input);
}

void Player::AssignState(PlayerState* state) {
	this->state = state;
}

void Player::AddVelocity(Vec2i velocity) {
	this->velocity = { this->velocity.x + velocity.x, this->velocity.y + velocity.y };
}

void Player::SetXVelocity(int xVelocity) {
	this->velocity.x = xVelocity;
}

void Player::SetYVelocity(int yVelocity) {
	this->velocity.y = yVelocity;
}

void Player::SetJumpingAndRising(bool isJumpingAndRising) {
	this->isJumping = isJumpingAndRising;
	this->isRising = isJumpingAndRising;
}

bool Player::GetIsJumping() {
	return isJumping;
}

bool Player::GetIsBlockedRight() {
	return isBlockedRight;
}

bool Player::GetIsBlockedLeft() {
	return isBlockedLeft;
}

void Player::SetRespawnPosition(Vec2i newRespawnPosition) {
	respawnPosition = newRespawnPosition;
}

void Player::Reset()
{
	position.x = respawnPosition.x;
	position.y = respawnPosition.y;
	Game::GetSoundManager()->StopMusic();
	Game::GetRenderer()->GetCamera()->Reset();
	Game::SetScrollStarted(false);
}

void Player::OnCollisionTouch(Collider* touched, Side side) {
	
	if (touched->GetLayer() == &CollisionLayer::Trap)
	{
		Reset();
	}
	else if (side == Side::Bottom) {
		isFalling = false;
		SetYVelocity(0);
		if (isJumping) {
			isJumping = false;
			AssignState(&PlayerState::standing);
			Enter();
		}
	}
	else if (side == Side::Left) {
		isBlockedLeft = true;
		SetXVelocity(0);
	}
	else if (side == Side::Right) {
		isBlockedRight = true;
		SetXVelocity(0);
	}
	else if (side == Side::Top) {
		SetYVelocity(-this->velocity.y);
	}
}

void Player::SetSpeedFactor(int factor) {
	speedFactor = factor;
}

int Player::GetSpeedFactor() {
	return speedFactor;
}

void Player::UpdateSpeed() {
	state->UpdateSpeed(*this);
}