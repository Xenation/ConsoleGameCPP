#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h"
#include "Constants.h"
#include "Camera.h"

class EntityManager {
public:
	static EntityManager& getInstance() {
		static EntityManager instance;
		return instance;
	}
	void RegisterEntity(Entity* entity);
	void UpdateAllEntities();
	void RenderAllEntities(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH], Camera* camera);
private:
	EntityManager();
	~EntityManager();
	EntityManager(EntityManager const&);	// Don't Implement
	void operator=(EntityManager const&);	// Don't implement
	std::vector<Entity*>* entities;
};

