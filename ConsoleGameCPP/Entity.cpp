#include "stdafx.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(Graphic* graphic, Pos pos) {
	this->graphic = graphic;
	this->position = pos;
	this->velocity = {1, 0};
	EntityManager::getInstance().RegisterEntity(this);
}


Entity::~Entity() {

}

void Entity::CopyToBuffer(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	graphic->CopyToBuffer(buffer, this->position);
}

void Entity::Update() {
	if (position.x > 60) {
		velocity.x = -1;
	}
	else if (position.x < 5) {
		velocity.x = 1;
	}
	if (position.y > 50) {
		velocity.y = -1;
	}
	else if (position.y < 5) {
		velocity.y = 1;
	}
	position.x += velocity.x;
	position.y += velocity.y;
}
