#pragma once
#include <Windows.h>
#include "Constants.h"
class Graphic;
class Entity;
class RenderLayer;

/*
===============================================================================
CLass that manages the rendering of the graphic elements
===============================================================================
*/
class GraphicRender {
public:
	GraphicRender(Entity* entity, RenderLayer* layer);
	~GraphicRender();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);

	// Accessors and mutators
	void SetLayer(RenderLayer* layer);
	RenderLayer* GetLayer();
private:
	unsigned int uid = 0;
	RenderLayer* layer;
	GraphicRender();
	Entity* entity;
};

