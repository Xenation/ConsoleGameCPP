#pragma once
#include <unordered_map>
class GraphicRender;

/*
===============================================================================
Class that manages the layers of the rendering
===============================================================================
*/
class RenderLayer {
public:
	// Higher means renderer last / in front
	const unsigned int layerIndex;
	// The list of graphic elements in this layer
	std::unordered_map<unsigned int, GraphicRender*>* renders;
	// The count of available layers
	static const unsigned int layerCount = 4;
	// The list of all the available layers
	static RenderLayer **const layers;
	// The layer for the background elements
	static RenderLayer *const Background;
	// The layer used by default
	static RenderLayer *const Default;
	// The layer for the decor elements (i.e: walls, spikes, ...)
	static RenderLayer *const Decor;
	// The layer for the player
	static RenderLayer *const Player;

	RenderLayer(unsigned int index);
	~RenderLayer();
	// Register the given element to be rendered in this layer 
	unsigned int Register(GraphicRender* render);
	// Unregister the given element
	void Unregister(unsigned int uid);
private:
	unsigned int currentUID = 0;
};

