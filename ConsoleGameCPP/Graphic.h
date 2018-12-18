#pragma once
#include <Windows.h>
#include "MathStructs.h"
#include "Constants.h"
#include "ConsoleColor.h"
class Camera;

/*
===============================================================================
Class used holds the information of the graphic elements
===============================================================================
*/
class Graphic {
public:
	int width = 0;
	int height = 0;
	wchar_t** contents;
	ConsoleColor foregroundColor;
	ConsoleColor backgroundColor;
protected:
	Graphic();
	~Graphic();
	Graphic(Graphic const&);
	void operator=(Graphic const&);
};

