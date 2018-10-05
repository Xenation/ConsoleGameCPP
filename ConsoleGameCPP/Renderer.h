#pragma once
#include <unordered_map>
class GraphicRender;
class Camera;
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
	unsigned int RegisterRender(GraphicRender* graphicRender);
	void UnregisterRender(unsigned int uid);
	inline Camera* getCamera() const { return camera; }
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
	std::unordered_map<unsigned int, GraphicRender*>* renders;
	unsigned int currentUID = 0;
};

