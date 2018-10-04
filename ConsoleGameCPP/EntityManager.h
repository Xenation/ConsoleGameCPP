#pragma once
#include <vector>
#include <Windows.h>
#include "Constants.h"
class Entity;
class Camera;
class EntityManager {
public:
	static EntityManager& getInstance() {
		static EntityManager instance;
		return instance;
	}
	void RegisterEntity(Entity* entity);
	void UpdateAllEntities();
private:
	EntityManager();
	~EntityManager();
	EntityManager(EntityManager const&);	// Don't Implement
	void operator=(EntityManager const&);	// Don't implement
	std::vector<Entity*>* entities;
};

