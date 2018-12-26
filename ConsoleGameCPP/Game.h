#pragma once
class Renderer;
class SoundManager;

/*
===============================================================================
CLass that holds important elements and information about the game
===============================================================================
*/
class Game {
public:

	// Accessors and mutators
	static Renderer* GetRenderer() {
		return renderer;
	}

	static void SetRenderer(Renderer* newRenderer) {
		renderer = newRenderer;
	}

	static SoundManager* GetSoundManager() {
		return soundManager;
	}

	static void SetSoundManager(SoundManager* newSoundManager) {
		soundManager = newSoundManager;
	}

	static bool GetScrollStarted() {
		return scrollStarted;
	}

	static void SetScrollStarted(bool newState) {
		scrollStarted = newState;
	}

	static bool GetIsEndReached() {
		return isEndReached;
	}

	static void SetIsEndReached(bool newState) {
		isEndReached = newState;
	}

private:
	Game();
	~Game();
	Game(Game const&);	// Don't Implement
	void operator=(Game const&);	// Don't implement
	static Renderer* renderer;
	static SoundManager* soundManager;
	static bool scrollStarted;
	static bool isEndReached;
};

