#pragma once

/*
===============================================================================
Class that manages the music
===============================================================================
*/
class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void StartMusic(); // Start the music (used at the beginning of the scrolling)
	void StopMusic(); // Stops the music (used when the player dies)
};

