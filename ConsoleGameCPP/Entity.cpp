#include "stdafx.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(Graphic* graphic, Pos pos) {
	this->graphic = graphic;
	this->position = pos;
	EntityManager::getInstance().RegisterEntity(this);
}


Entity::~Entity() {

}

void Entity::Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	graphic->Render(buffer, this->position);
}

void Entity::Update() {
	
}
