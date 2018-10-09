#pragma once
#include <Windows.h>
#include "Constants.h"
class Graphic;
class Entity;
class RenderLayer;
class GraphicRender {
public:
	Entity* entity;
	GraphicRender(Entity* entity, RenderLayer* layer);
	~GraphicRender();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
	void setLayer(RenderLayer* layer);
	RenderLayer* getLayer();
private:
	unsigned int uid = 0;
	RenderLayer* layer;
	GraphicRender();
};

