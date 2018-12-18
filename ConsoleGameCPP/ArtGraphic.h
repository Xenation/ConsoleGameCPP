#pragma once
#include "Graphic.h"
class Camera;

/*
===============================================================================
Class that holds all the graphic art of an entity
===============================================================================
*/
class ArtGraphic : public Graphic {
public:
	// 2 constructor overloads for all cases of use
	ArtGraphic(const wchar_t** cont, int width, int height);
	ArtGraphic(wchar_t** cont, int width, int height);
	~ArtGraphic();
};

