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
	// Initializes window and rendering variables
	void Initialize();
	// Resets the timer (making the start of the frame now)
	void ResetFrameTimer();
	// Renders the current game's state to the window
	void Render();
	// Marks the end of a frame
	void EndFrame();
	// Clears the frame buffer
	void ClearBuffer();

	// Accessors
	// Returns the number of rendered frames
	int GetFrameCount() const;
	// Returns the time taken to render the frame
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

