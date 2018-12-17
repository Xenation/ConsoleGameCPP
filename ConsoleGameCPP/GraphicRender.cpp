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
	if (entity->graphic == nullptr) return;
	Box camBox = Game::renderer->getCamera()->GetBoundingBox();
	Vec2i screenPos = entity->position - Game::renderer->getCamera()->GetPosition();
	for (int y = 0; y < entity->graphic->height; y++) {
		for (int x = 0; x < entity->graphic->width; x++) {
			if (!isInBox(camBox, {entity->position.x + x, entity->position.y + y})) continue;
			buffer[screenPos.y + y][screenPos.x + x].Char.UnicodeChar = entity->graphic->contents[y][x];
			buffer[screenPos.y + y][screenPos.x + x].Attributes = (entity->graphic->backgroundColor << 4) | entity->graphic->foregroundColor;
		}
	}
}

void GraphicRender::setLayer(RenderLayer* layer) {
	this->layer->Unregister(uid);
	this->layer = layer;
	uid = this->layer->Register(this);
}

RenderLayer* GraphicRender::getLayer() {
	return layer;
}
