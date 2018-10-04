#pragma once
#include <Windows.h>
#include "MathStructs.h"
#include "Constants.h"
class Camera;
class Graphic {
public:
	int width = 0;
	int height = 0;
	char** contents;
protected:
	Graphic();
	~Graphic();
	Graphic(Graphic const&);
	void operator=(Graphic const&);
};

