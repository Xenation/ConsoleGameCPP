#include "stdafx.h"

#include "EntityManager.h"

#include "Entity.h"
#include "PhysicsManager.h"


EntityManager::EntityManager() {
	entities = new std::vector<Entity*>();
}


EntityManager::~EntityManager() {
	delete entities;
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
