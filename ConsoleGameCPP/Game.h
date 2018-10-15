#pragma once
class Renderer;
class SoundManager;

class Game {
public:
	static Renderer* renderer;
	static SoundManager* soundManager;
	static bool scrollStarted;
private:
	Game();
	~Game();
	Game(Game const&);	// Don't Implement
	void operator=(Game const&);	// Don't implement
};

