#pragma once

#include <Windows.h>
#include <cwchar>
#include "Constants.h"
#include "EntityManager.h"
#include "NYTimer.h"
#include "Time.h"
#include "Camera.h"

class Renderer {
public:
	Renderer(Camera* camera, int frameCap = 0);
	~Renderer();
	void Initialize();
	void ResetFrameTimer();
	void Render();
	void EndFrame();
	void ClearBuffer();
	int getFrameCount();
	float getRenderTime();
private:
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	HANDLE outputHandle;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rectRegion;
	float frameTime = 0;
	float frameStart = 0;
	float renderTime = 0;
	int frameCount = 0;
};

