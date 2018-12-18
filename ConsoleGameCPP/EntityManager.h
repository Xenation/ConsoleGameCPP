#pragma once
#include <unordered_map>
#include <Windows.h>
#include "Constants.h"
class Entity;
class Camera;

/*
===============================================================================
Class that manages the entities present in the game
===============================================================================
*/
class EntityManager {
public:
	// Singleton
	static EntityManager& GetInstance() {
		static EntityManager instance;
		return instance;
	}
	unsigned int RegisterEntity(Entity* entity);
	void UnregisterEntity(unsigned int uid);
	void UpdateAllEntities();
private:
	EntityManager();
	~EntityManager();
	EntityManager(EntityManager const&);	// Don't Implement
	void operator=(EntityManager const&);	// Don't implement
	std::unordered_map<unsigned int, Entity*>* entities;
	unsigned int currentUID = 0;
};

