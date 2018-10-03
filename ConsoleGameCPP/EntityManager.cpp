#include "stdafx.h"
#include "EntityManager.h"
#include <iostream>
#include <iomanip>
#include "PhysicsManager.h"


EntityManager::EntityManager() {
	entities = new std::vector<Entity*>();
}


EntityManager::~EntityManager() {
	delete(entities);
	std::cout << "EntityManager Disposed!" << std::endl;
}

void EntityManager::RegisterEntity(Entity* entity) {
	this->entities->push_back(entity);
}

void EntityManager::UpdateAllEntities() {
	for (unsigned int i = 0; i < entities->size(); i++) {
		entities->at(i)->Update();
	}
	PhysicsManager::getInstance().UpdateAllColliders();
}

void EntityManager::RenderAllEntities(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	for (unsigned int i = 0; i < entities->size(); i++) {
		entities->at(i)->Render(buffer);
	}
}
