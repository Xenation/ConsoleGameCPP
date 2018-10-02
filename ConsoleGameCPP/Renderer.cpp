#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer(int frameCap = 0) {
	if (frameCap != 0) {
		frameTime = 1.0f / frameCap * 1000;
	} else {
		frameTime = 0;
	}
	frameStart = 0;
	Time::getInstance();
	dwBufferSize = {SCREEN_WIDTH, SCREEN_HEIGHT};
	dwBufferCoord = {0, 0};
	rectRegion = {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};
}


Renderer::~Renderer() {
	
}

void Renderer::Initialize() {
	outputHandle = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);

	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, SCREEN_WIDTH * 8 + 50, SCREEN_HEIGHT * 16 + 50, TRUE); // TODO use detected font size
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	ReadConsoleOutput(outputHandle, (CHAR_INFO *) buffer, dwBufferSize, dwBufferCoord, &rectRegion);
}

void Renderer::ResetFrameTimer() {
	frameStart = Time::time();
}

void Renderer::Render() {
	EntityManager::getInstance().RenderAllEntities(buffer);
	WriteConsoleOutput(outputHandle, (CHAR_INFO *) buffer, dwBufferSize, dwBufferCoord, &rectRegion);
}

void Renderer::ClearBuffer() {
	for (int y = 0; y < dwBufferSize.Y; y++) {
		for (int x = 0; x < dwBufferSize.X; x++) {
			buffer[y][x] = {};
		}
	}
}

void Renderer::EndFrame() {
	renderTime = Time::time() - frameStart;
	float toSleep = frameTime - renderTime;
	if (toSleep > 0) {
		Sleep(toSleep);
	}
	Time::getInstance().deltaTime = Time::time() - frameStart;
	frameStart = Time::time();
	frameCount++;
}

int Renderer::getFrameCount() {
	return frameCount;
}

float Renderer::getRenderTime() {
	return renderTime;
}
