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

//bool endRequested = true;

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
array<bool, 7> inputKeys; // Better to use STL array than a built-in table according to Bjarne Stroustrup
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
	platGen->generateWorld("world_final.txt");

	// Get a reference to the platform generator in Camera, and initialize the freeze position
	// TODO : Do all of the initializations inside the main camera ?
	mainCamera->SetPlatformGenerator(platGen);
	mainCamera->InitializeFreezePosition();
	mainCamera->InitializeSpeedUpPosition();

	Player* player = new Player(AnimationHolder::instance().GetPlayerStandingGraph(), platGen->getPlayerInitialPosition(), platGen); // Initialize player in the standing position
	mainCamera->SetFollowed(player);


	TextGraphic* statsTxt = new TextGraphic();
	Entity* stats = new Entity(statsTxt, { 10, 0 });

	Game::renderer->ResetFrameTimer();

	while (!closeRequested) {

		// Check inputs
		inputKeys[D] = GetAsyncKeyState('D');
		inputKeys[RIGHT_ARROW] = GetAsyncKeyState(VK_RIGHT);
		inputKeys[Q] = GetAsyncKeyState('Q');
		inputKeys[A] = GetAsyncKeyState('A');
		inputKeys[LEFT_ARROW] = GetAsyncKeyState(VK_LEFT);
		inputKeys[SPACE] = GetAsyncKeyState(VK_SPACE);
		inputKeys[ESCAPE] = GetAsyncKeyState(VK_ESCAPE);

		player->handleInput(inputKeys);

		if (inputKeys[ESCAPE]) {
			closeRequested = true; // This while-loop will be the last
		}



		//if (!_kbhit()) // Keyboard inputs
		//{
		//	int getChar = _getch(); // _getch() flushes the content, so we need to stock it into a variable before testing

		//	player->handleInput(getChar);
		//}

		//waiting for player to advance
		if (!Game::scrollStarted) {
			if (player->position.x >= Game::renderer->getCamera()->GetPosition().x + PLAYER_POS_DEBUT_SCROLLING) {
				Game::soundManager->StartMusic();
				// say to the camera to move
				mainCamera->SetHasStarted(true);
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

	//if (endRequested)
	//{
	//	float endtimer = 0.0f;

	//	// Generate end screen
	//	Game::renderer->ClearBuffer();
	//	ImageASCII *img = new ImageASCII();
	//	if (img->genererImage("end_final.txt")) {
	//		img->parcourirTableau(img->getImage());
	//	}

	//	while (endtimer <= 4.0f) {
	//		endtimer += Time::getDeltaTime();
	//	}
	//}

	return 0;
}