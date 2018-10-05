#include "stdafx.h"

#include "Entity.h"

#include "Graphic.h"
#include "GraphicRender.h"
#include "Collider.h"
#include "EntityManager.h"


Entity::Entity(Graphic* graphic, Vec2i pos, bool hasCollider) {
	this->graphic = graphic;
	if (graphic != nullptr) {
		this->graphicRender = new GraphicRender(this, this->graphic);
	}
	this->position = pos;
	if (hasCollider) {
		this->collider = new Collider(this, &this->position, { this->graphic->width, this->graphic->height });
	}
	EntityManager::getInstance().RegisterEntity(this);
}


Entity::~Entity() {
	delete collider;
}

void Entity::Update() {
	
}

void Entity::OnCollisionTouch(Collider* touched, Side side) {

}
