#pragma once

#include <Windows.h>
#include <cwchar>
#include "Constants.h"
#include "EntityManager.h"
#include "NYTimer.h"
#include "Time.h"

class Renderer {
public:
	Renderer(int frameCap);
	~Renderer();
	void Initialize();
	void ResetFrameTimer();
	void Render();
	void EndFrame();
	void ClearBuffer();
	int getFrameCount();
private:
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	HANDLE outputHandle;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rectRegion;
	float frameTime = 0;
	float frameStart = 0;
	int frameCount = 0;
};

