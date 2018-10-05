#include "stdafx.h"

#include <Windows.h>
#include "Constants.h"

#include "GraphicRender.h"

#include "MathStructs.h"
#include "Graphic.h"
#include "Entity.h"
#include "Renderer.h"
#include "Camera.h"
#include "Game.h"


GraphicRender::GraphicRender(Entity* entity) : entity(entity) {
	uid = Game::renderer->RegisterRender(this);
}


GraphicRender::~GraphicRender() {
	Game::renderer->UnregisterRender(uid);
}

void GraphicRender::Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	if (entity->graphic == nullptr) return;
	Box camBox = Game::renderer->getCamera()->getBoundingBox();
	Vec2i screenPos = entity->position - Game::renderer->getCamera()->getPosition();
	for (int y = 0; y < entity->graphic->height; y++) {
		for (int x = 0; x < entity->graphic->width; x++) {
			if (!isInBox(camBox, {entity->position.x + x, entity->position.y + y})) continue;
			buffer[screenPos.y + y][screenPos.x + x].Char.AsciiChar = entity->graphic->contents[y][x];
			buffer[screenPos.y + y][screenPos.x + x].Attributes = 0x0E;
		}
	}
}
