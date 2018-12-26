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
	// The width in characters
	int width = 0;
	// The height in characters
	int height = 0;
	// The contents (array)
	wchar_t** contents;
	// The foreground color of all the characters
	ConsoleColor foregroundColor;
	// The background color of all the characters
	ConsoleColor backgroundColor;
protected:
	Graphic();
	~Graphic();
	Graphic(Graphic const&);
	void operator=(Graphic const&);
};

