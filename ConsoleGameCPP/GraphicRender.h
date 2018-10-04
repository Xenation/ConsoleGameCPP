#pragma once
class Graphic;
class Entity;
class GraphicRender {
public:
	Entity* entity;
	GraphicRender(Entity* entity, Graphic* toRender);
	~GraphicRender();
	virtual void Render(CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
private:
	Graphic* toRender;
	unsigned int uid = 0;
	GraphicRender();
};

