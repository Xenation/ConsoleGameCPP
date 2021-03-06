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
std::array<bool, 7> inputKeys; // Better to use STL array than a built-in table according to Bjarne Stroustrup
						  //inputKeys[INPUT_KEY_COUNT];

int main(int argc, char* argv[]) {
	// Initializing handles
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)(ctrl_handler), TRUE); // Used for mouse events

	Camera* mainCamera = new Camera({ 0, 0 }, SCREEN_WIDTH, SCREEN_HEIGHT);
	Game::SetRenderer(new Renderer(mainCamera, 30));
	Game::GetRenderer()->Initialize();

	Game::SetSoundManager(new SoundManager()); // Load the music

	Game::SetScrollStarted(false);

	// Generate title screen
	ImageASCII *img = new ImageASCII();
	if (img->GenerateImage("title.txt")) {
		img->SweepTable(img->GetImage());
	}

	// Wait for player input to start the game
	while (!GetAsyncKeyState(VK_RETURN)) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit(0);
		}
		Sleep(10);
	}

	PlatformGenerator *platGen = new PlatformGenerator();
	platGen->GenerateWorld("world_final.txt");

	// Get a reference to the platform generator in Camera, and initialize all the positions	
	mainCamera->InitializeAllPositions(platGen);

	Player* player = new Player(AnimationHolder::instance().GetPlayerStandingGraph(), platGen->GetPlayerInitialPosition(), platGen); // Initialize player in the standing position
	mainCamera->SetFollowed(player);

	TextGraphic* statsTxt = new TextGraphic();
	Entity* stats = new Entity(statsTxt, { 10, 0 });

	Game::GetRenderer()->ResetFrameTimer();

	// Loop until escape is pressed or the end of the game is reached
	while (!closeRequested && !Game::GetIsEndReached()) {

		// Check inputs
		inputKeys[D] = GetAsyncKeyState('D');
		inputKeys[RIGHT_ARROW] = GetAsyncKeyState(VK_RIGHT);
		inputKeys[Q] = GetAsyncKeyState('Q');
		inputKeys[A] = GetAsyncKeyState('A');
		inputKeys[LEFT_ARROW] = GetAsyncKeyState(VK_LEFT);
		inputKeys[SPACE] = GetAsyncKeyState(VK_SPACE);
		inputKeys[ESCAPE] = GetAsyncKeyState(VK_ESCAPE);

		player->HandleInput(inputKeys);

		if (inputKeys[ESCAPE]) {
			closeRequested = true; // This while-loop will be the last
		}

		//waiting for player to advance
		if (!Game::GetScrollStarted()) {
			if (player->GetPosition().x >= Game::GetRenderer()->GetCamera()->GetPosition().x + PLAYER_POS_DEBUT_SCROLLING) {
				Game::GetSoundManager()->StartMusic();
				// say to the camera to move
				mainCamera->SetHasStarted(true);
				Game::SetScrollStarted(true);
			}
		}

		// Update
		EntityManager::GetInstance().UpdateAllEntities();
		std::string str = "fc: " + std::to_string(Game::GetRenderer()->GetFrameCount()) + " / dt: " + std::to_string(Time::GetDeltaTime()) + " / rt: " + std::to_string(Game::GetRenderer()->GetRenderTime());
		statsTxt->SetText(str.c_str());

		// Render
		Game::GetRenderer()->Render();

		Game::GetRenderer()->EndFrame();

		Game::GetRenderer()->ClearBuffer(); // TODO maybe replace by buffer swap method
	}

	// Launches end screen if the end was reached
	if (Game::GetIsEndReached()) {

		// Timers for timing the end
		float endtimer = 0.0f;
		float startTime = Time::time() / 1000; // Current time in seconds
		float endTime = startTime + 7.0f;

		// Generates the end screen
		Game::GetRenderer()->ClearBuffer();
		ImageASCII *endImg = new ImageASCII();
		if (endImg->GenerateImage("end_final.txt")) {
			endImg->SweepTable(endImg->GetImage());
		}

		// Stops the game only after the endTime has been reached
		while (endtimer <= endTime) {
			endtimer = Time::time() / 1000;
		}
	}

	return 0;
}