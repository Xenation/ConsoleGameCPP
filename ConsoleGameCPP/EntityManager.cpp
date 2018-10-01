#include "stdafx.h"
#include "EntityManager.h"


EntityManager::EntityManager() {
	entities = new std::vector<Entity*>();
}


EntityManager::~EntityManager() {
	delete(entities);
}

void EntityManager::RegisterEntity(Entity* entity) {
	this->entities->push_back(entity);
}

void EntityManager::UpdateAllEntities() {
	for (int i = 0; i < entities->size(); i++) {
		entities->at(i)->Update();
	}
}

void EntityManager::RenderAllEntities(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (int i = 0; i < entities->size(); i++) {
		entities->at(i)->CopyToBuffer(buffer);
	}
}
