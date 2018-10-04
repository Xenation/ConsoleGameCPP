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
#include "Renderer.h"
#include "Player.h"
#include "Constants.h"
#include <array>
#include "AnimationHolder.h"
#include "PlatformGenerator.h"

using namespace std; // TODO : à retirer

bool closeRequested = false;
BOOL ctrl_handler(DWORD event) {
	if (event == CTRL_CLOSE_EVENT) {
		closeRequested = true;
		//Sleep(20000);
		return TRUE;
	}
}

// Initializing input keys array
array<bool, 4> inputKeys; // Better to use STL array than a built-in table according to Bjarne Stroustrup
//inputKeys[INPUT_KEY_COUNT];

int main(int argc, char* argv[]) {
	// Initializing handles
	SetConsoleCtrlHandler((PHANDLER_ROUTINE) (ctrl_handler), TRUE); // Used for mouse events

	Camera* mainCamera = new Camera({ 0, 0 }, SCREEN_WIDTH, SCREEN_HEIGHT);
	Renderer* renderer = new Renderer(mainCamera, 30);
	renderer->Initialize();

	Player* player = new Player(AnimationHolder::instance().getPlayerStandingGraph(), { 10, 20 }); // Initialize player in the standing position

	PlatformGenerator *platGen = new PlatformGenerator();
	platGen->generateWorld("world.txt");

	//const char** playerGraph;
	//playerGraph = new const char*[3];
	//playerGraph[0] = "  o ";
	//playerGraph[1] = "\\/|\\";
	//playerGraph[2] = " / \\";
	//Graphic* graph = new ArtGraphic(playerGraph, 4, 3);
	//Player* player = new Player(graph, { 10, 20 });
	//Entity* entity = new BouncingEntity(graph, {1, 1});
	//Entity* entity2 = new BouncingEntity(graph, {8, 8});

	TextGraphic* statsTxt = new TextGraphic();
	Entity* stats = new Entity(statsTxt, {10, 0});

	//Entity* colliderEnt = new Entity(graph, {10, 12}, true);
	//colliderEnt->collider->layer = &CollisionLayer::Decor;
	//Entity* colliderEnt2 = new Entity(graph, { 50, 30 }, true);
	//colliderEnt2->collider->layer = &CollisionLayer::Decor;
	//Entity* colliderEnt3 = new Entity(graph, { 30, 12 }, true);
	//colliderEnt3->collider->layer = &CollisionLayer::Decor;

	renderer->ResetFrameTimer();
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

		mainCamera->Update(); // TODO make camera an entity with no Graphic

		//if (!_kbhit()) // Keyboard inputs
		//{
		//	int getChar = _getch(); // _getch() flushes the content, so we need to stock it into a variable before testing

		//	player->handleInput(getChar);
		//}

		// Update
		EntityManager::getInstance().UpdateAllEntities();
		string str = "fc: " + to_string(renderer->getFrameCount()) + " / dt: " + to_string(Time::getDeltaTime()) + " / rt: " + to_string(renderer->getRenderTime());
		statsTxt->setText(str.c_str());

		// Render
		renderer->Render();

		renderer->EndFrame();

		renderer->ClearBuffer(); // TODO maybe replace by buffer swap method
	}

	return 0;
}
