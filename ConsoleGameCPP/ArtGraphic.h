#pragma once
#include "Graphic.h"
class Camera;
class ArtGraphic : public Graphic {
public:
	ArtGraphic(const wchar_t** cont, int width, int height);
	ArtGraphic(wchar_t** cont, int width, int height);
	~ArtGraphic();
};

