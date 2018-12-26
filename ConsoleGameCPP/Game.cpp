#include "stdafx.h"

#include "Game.h"

Renderer* Game::renderer = nullptr;
SoundManager* Game::soundManager = nullptr;
bool Game::scrollStarted = false;
bool Game::isEndReached = false;