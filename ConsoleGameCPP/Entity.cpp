#include "stdafx.h"

#include "Entity.h"

#include "Graphic.h"
#include "GraphicRender.h"
#include "RenderLayer.h"
#include "Collider.h"
#include "EntityManager.h"


Entity::Entity(Graphic* graphic, Vec2i pos, bool hasCollider) {
	this->graphic = graphic;
	if (graphic != nullptr) {
		this->graphicRender = new GraphicRender(this, RenderLayer::Default);
	}
	this->position = pos;
	if (hasCollider) {
		this->collider = new Collider(this, &this->position, { this->graphic->width, this->graphic->height });
	}
	uid = EntityManager::GetInstance().RegisterEntity(this);
}

Entity::~Entity() {
	EntityManager::GetInstance().UnregisterEntity(uid);
	delete collider;
}

void Entity::Update() {
	
}

void Entity::OnCollisionTouch(Collider* touched, Side side) {

}

void Entity::SetGraphic(Graphic* newGraphic) {
	graphic = newGraphic;
}

Graphic* Entity::GetGraphic() const {
	return graphic;
}

Vec2i Entity::GetPosition() const {
	return position;
}

Collider* Entity::GetCollider() const {
	return collider;
}

GraphicRender* Entity::GetGraphicRender() const {
	return graphicRender;
}
