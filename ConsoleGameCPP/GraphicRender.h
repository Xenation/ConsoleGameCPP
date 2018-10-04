#pragma once
class GraphicRender {
public:
	GraphicRender(Graphic* toRender);
	~GraphicRender();
	virtual void Render();
private:
	Graphic* toRender;
	GraphicRender();
};

