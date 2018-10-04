#pragma once
#include "Graphic.h"
class Camera;
class ArtGraphic : public Graphic {
public:
	ArtGraphic(const char** cont, int width, int height);
	ArtGraphic(char** cont, int width, int height);
	~ArtGraphic();
};

