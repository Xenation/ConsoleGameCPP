#include "stdafx.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(Graphic* graphic, Pos pos, bool hasCollider) {
	this->graphic = graphic;
	this->position = pos;
	if (hasCollider) {
		this->collider = new Collider(this, &this->position, { this->graphic->width, this->graphic->height });
	}
	EntityManager::getInstance().RegisterEntity(this);
}


Entity::~Entity() {
	delete collider;
}

void Entity::Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	graphic->Render(buffer, this->position);
}

void Entity::Update() {
	
}

void Entity::OnCollisionTouch(Collider* touched, Side side) {

}
