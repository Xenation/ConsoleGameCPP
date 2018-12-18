#include "stdafx.h"

#include "GraphicRender.h"

#include "MathStructs.h"
#include "Graphic.h"
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"
#include "Game.h"
#include "RenderLayer.h"


GraphicRender::GraphicRender(Entity* entity, RenderLayer* layer) : entity(entity), layer(layer) {
	uid = this->layer->Register(this);
}

GraphicRender::~GraphicRender() {
	layer->Unregister(uid);
}

void GraphicRender::Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	if (entity->GetGraphic() == nullptr) return;
	Box camBox = Game::GetRenderer()->GetCamera()->GetBoundingBox();
	Vec2i screenPos = entity->GetPosition() - Game::GetRenderer()->GetCamera()->GetPosition();
	for (int y = 0; y < entity->GetGraphic()->height; y++) {
		for (int x = 0; x < entity->GetGraphic()->width; x++) {
			if (!isInBox(camBox, {entity->GetPosition().x + x, entity->GetPosition().y + y})) continue;
			buffer[screenPos.y + y][screenPos.x + x].Char.UnicodeChar = entity->GetGraphic()->contents[y][x];
			buffer[screenPos.y + y][screenPos.x + x].Attributes = (entity->GetGraphic()->backgroundColor << 4) | entity->GetGraphic()->foregroundColor;
		}
	}
}

void GraphicRender::SetLayer(RenderLayer* layer) {
	this->layer->Unregister(uid);
	this->layer = layer;
	uid = this->layer->Register(this);
}

RenderLayer* GraphicRender::GetLayer() {
	return layer;
}
