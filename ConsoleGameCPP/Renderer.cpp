#include "stdafx.h"

#include <Windows.h>
#include "Constants.h"

#include "Renderer.h"

#include "GraphicRender.h"
#include "RenderLayer.h"
#include "Camera.h"
#include "Time.h"

static UINT oldConsoleCP;

Renderer::Renderer(Camera* camera, int frameCap) {
	if (frameCap != 0) {
		frameTime = 1.0f / frameCap * 1000;
	} else {
		frameTime = 0;
	}
	frameStart = 0;
	Time::GetInstance();
	dwBufferSize = { camera->GetWidth(), camera->GetHeight() };
	dwBufferCoord = {0, 0};
	rectRegion = {0, 0, camera->GetWidth() - 1, camera->GetHeight() - 1};
	this->camera = camera;
}


Renderer::~Renderer() {
	SetConsoleCP(oldConsoleCP);
}

void Renderer::Initialize() {
	// HANDLE rHnd; /* read (input) handle */

	/* Window size coordinates, be sure to start index at zero! */
	//SMALL_RECT windowSize = { 0, 0, 109, 39 };
	SMALL_RECT windowSize = { 0, 0, camera->GetWidth() - 1, camera->GetHeight() - 1 };


	/* A COORD struct for specificying the console's screen buffer dimensions */
	COORD bufferSize = { camera->GetWidth(), camera->GetHeight() };

	  /* initialize handles */
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// rHnd = GetStdHandle(STD_INPUT_HANDLE);

	// Set the console title
	SetConsoleTitle(L"Stick of the tiger");

	/* Set the window size */
	SetConsoleWindowInfo(outputHandle, TRUE, &windowSize);

	oldConsoleCP = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);

	/* Set the screen's buffer size */
	SetConsoleScreenBufferSize(outputHandle, bufferSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);

	// Hide cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(outputHandle, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(outputHandle, &cursorInfo);
}

void Renderer::ResetFrameTimer() {
	frameStart = Time::time();
}

void Renderer::Render() {
	for (int i = 0; i < RenderLayer::layerCount; i++) {
		if (RenderLayer::layers[i] == nullptr) continue;
		for (std::pair<unsigned int, GraphicRender*> renderPair : *RenderLayer::layers[i]->renders) {
			renderPair.second->Render(buffer);
		}
	}
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
	Time::GetInstance().SetDeltaTime(Time::time() - frameStart);
	frameStart = Time::time();
	frameCount++;
}

int Renderer::GetFrameCount() const {
	return frameCount;
}

float Renderer::GetRenderTime() const {
	return renderTime;
}
