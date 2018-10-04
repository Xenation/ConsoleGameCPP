#pragma once
class Game {
public:
	static Renderer* renderer;
private:
	Game();
	~Game();
	Game(Game const&);	// Don't Implement
	void operator=(Game const&);	// Don't implement
};

