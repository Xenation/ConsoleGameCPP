// ConsoleGameCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Windows.h"
#include "Graphic.h"
#include "ArtGraphic.h"
#include "TextGraphic.h"
#include "Constants.h"
#include "Entity.h"
#include "BouncingEntity.h"
#include "EntityManager.h"
#include "GraphicRender.h"
#include "Renderer.h"
#include "Player.h"
#include "Constants.h"
#include <array>
#include "AnimationHolder.h"
#include "PlatformGenerator.h"
#include "Time.h"
#include "Game.h"
#include "Camera.h"
#include "SoundManager.h"

using namespace std; // TODO : à retirer

bool closeRequested = false;

bool gameStart = false;

const int PLAYER_POS_DEBUT_SCROLLING = 20;

BOOL ctrl_handler(DWORD event) {
	if (event == CTRL_CLOSE_EVENT) {
		closeRequested = true;
		//Sleep(20000);
		return TRUE;
	}
	return TRUE;
}

// Initializing input keys array
array<bool, 4> inputKeys; // Better to use STL array than a built-in table according to Bjarne Stroustrup
						  //inputKeys[INPUT_KEY_COUNT];

int main(int argc, char* argv[]) {
	// Initializing handles
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)(ctrl_handler), TRUE); // Used for mouse events

	Camera* mainCamera = new Camera({ 0, 0 }, SCREEN_WIDTH, SCREEN_HEIGHT);
	Game::renderer = new Renderer(mainCamera, 30);;
	Game::renderer->Initialize();

	Game::soundManager = new SoundManager(); // Load the music

	Game::scrollStarted = false;

	// Generate title screen
	ImageASCII *img = new ImageASCII();
	if (img->genererImage("title.txt")) {
		img->parcourirTableau(img->getImage());
	}

	// Wait for player input to start the game
	while (!GetAsyncKeyState(VK_RETURN)) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit(0);
		}
		Sleep(10);
	}

	PlatformGenerator *platGen = new PlatformGenerator();
	platGen->generateWorld("world_test.txt");

	// Get a reference to the platform generator in Camera, and initialize the freeze position
	mainCamera->setPlatformGenerator(platGen);
	mainCamera->initializeFreezePosition();

	Player* player = new Player(AnimationHolder::instance().getPlayerStandingGraph(), platGen->getPlayerInitialPosition(), platGen); // Initialize player in the standing position
	mainCamera->followed = player;


	TextGraphic* statsTxt = new TextGraphic();
	Entity* stats = new Entity(statsTxt, { 10, 0 });


	Game::renderer->ResetFrameTimer();

	while (!closeRequested) {

		// Check inputs

		if (GetAsyncKeyState(VK_ESCAPE)) { // TODO : fermer immédiatement (close ?)
			closeRequested = true;
		}

		// TODO: Use an enum to have a better understanding of this
		inputKeys[0] = GetAsyncKeyState('D');
		inputKeys[1] = GetAsyncKeyState('Q');
		inputKeys[2] = GetAsyncKeyState('A');
		inputKeys[3] = GetAsyncKeyState(VK_SPACE);

		player->handleInput(inputKeys);

		//if (!_kbhit()) // Keyboard inputs
		//{
		//	int getChar = _getch(); // _getch() flushes the content, so we need to stock it into a variable before testing

		//	player->handleInput(getChar);
		//}

		//waiting for player to advance
		if (!Game::scrollStarted) {
			if (player->position.x >= Game::renderer->getCamera()->getPosition().x + PLAYER_POS_DEBUT_SCROLLING) {
				Game::soundManager->StartMusic();
				// say to the camera to move
				mainCamera->hasStarted = true;
				Game::scrollStarted = true;
			}
		}


		// Update
		EntityManager::getInstance().UpdateAllEntities();
		string str = "fc: " + to_string(Game::renderer->getFrameCount()) + " / dt: " + to_string(Time::getDeltaTime()) + " / rt: " + to_string(Game::renderer->getRenderTime());
		statsTxt->setText(str.c_str());

		// Render
		Game::renderer->Render();

		Game::renderer->EndFrame();

		Game::renderer->ClearBuffer(); // TODO maybe replace by buffer swap method
	}

	return 0;
}