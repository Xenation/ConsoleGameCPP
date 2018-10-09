#include "stdafx.h"

#include "RenderLayer.h"

#include "GraphicRender.h"
#include "Game.h"
#include "Renderer.h"


RenderLayer **const RenderLayer::layers = new RenderLayer*[RenderLayer::layerCount]();
RenderLayer *const RenderLayer::Background = new RenderLayer(0);
RenderLayer *const RenderLayer::Default = new RenderLayer(1);
RenderLayer *const RenderLayer::Decor = new RenderLayer(3);
RenderLayer *const RenderLayer::Player = new RenderLayer(2);

RenderLayer::RenderLayer(unsigned int index) : layerIndex(index), renders(new std::unordered_map<unsigned int, GraphicRender*>()) {
	RenderLayer::layers[layerIndex] = this;
}

RenderLayer::~RenderLayer() {
	RenderLayer::layers[layerIndex] = nullptr;
	delete renders;
}

unsigned int RenderLayer::Register(GraphicRender* render) {
	(*renders)[currentUID] = render;
	return currentUID++;
}

void RenderLayer::Unregister(unsigned int uid) {
	(*renders).erase(uid);
}
