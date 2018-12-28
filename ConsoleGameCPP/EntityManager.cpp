#include "stdafx.h"

#include "EntityManager.h"

#include "Entity.h"
#include "PhysicsManager.h"


EntityManager::EntityManager() : entities(new std::unordered_map<unsigned int, Entity*>()) {
	
}


EntityManager::~EntityManager() {
	delete entities;
}

unsigned int EntityManager::RegisterEntity(Entity* entity) {
	(*entities)[currentUID] = entity;
	return currentUID++;
}

void EntityManager::UnregisterEntity(unsigned int uid) {
	entities->erase(uid);
}

void EntityManager::UpdateAllEntities() {
	for (std::pair<unsigned int, Entity*> pair : *entities) {
		pair.second->Update();
	}
	PhysicsManager::GetInstance().UpdateAllColliders();
}

int EntityManager::GetSizeList() {
	return entities->size();
}
