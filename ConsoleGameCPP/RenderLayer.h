#pragma once
#include <unordered_map>
class GraphicRender;
class RenderLayer {
public:
	const unsigned int layerIndex;
	std::unordered_map<unsigned int, GraphicRender*>* renders;
	static const unsigned int layerCount = 4;
	static RenderLayer **const layers;
	static RenderLayer *const Background;
	static RenderLayer *const Default;
	static RenderLayer *const Decor;
	static RenderLayer *const Player;
	RenderLayer(unsigned int index);
	~RenderLayer();
	unsigned int Register(GraphicRender* render);
	void Unregister(unsigned int uid);
private:
	unsigned int currentUID = 0;
};

