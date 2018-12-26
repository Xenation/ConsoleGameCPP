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
	if (entity->GetGraphic() == nullptr) return; // When nothing to render
	Box camBox = Game::GetRenderer()->GetCamera()->GetBoundingBox(); // box representing what is viewed by the camera
	Vec2i screenPos = entity->GetPosition() - Game::GetRenderer()->GetCamera()->GetPosition(); // Position of the entity in screen space
	for (int y = 0; y < entity->GetGraphic()->height; y++) {
		for (int x = 0; x < entity->GetGraphic()->width; x++) {
			if (!isInBox(camBox, {entity->GetPosition().x + x, entity->GetPosition().y + y})) continue; // check whether the current character is in the screen
			buffer[screenPos.y + y][screenPos.x + x].Char.UnicodeChar = entity->GetGraphic()->contents[y][x]; // Set the character
			buffer[screenPos.y + y][screenPos.x + x].Attributes = (entity->GetGraphic()->backgroundColor << 4) | entity->GetGraphic()->foregroundColor; // Set the colors
		}
	}
}

void GraphicRender::SetLayer(RenderLayer* layer) {
	this->layer->Unregister(uid); // Unregister from current layer
	this->layer = layer; // Change layer
	uid = this->layer->Register(this); // Register into new layer
}

RenderLayer* GraphicRender::GetLayer() {
	return layer;
}
