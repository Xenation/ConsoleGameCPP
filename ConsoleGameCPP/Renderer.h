#pragma once
#include <unordered_map>
class GraphicRender;
class Camera;
class RenderLayer;

/*
===============================================================================
Class that manages the rendering
===============================================================================
*/
class Renderer {
public:
	Renderer(Camera* camera, int frameCap = 0);
	~Renderer();
	void Initialize();
	void ResetFrameTimer();
	void Render();
	void EndFrame();
	void ClearBuffer();

	// Accessors
	int GetFrameCount() const;
	float GetRenderTime() const;
	inline Camera* GetCamera() const { return camera; }
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
	Camera* camera;
};

