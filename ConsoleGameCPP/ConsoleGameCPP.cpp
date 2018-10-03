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

using namespace std;

bool closeRequested = false;
BOOL ctrl_handler(DWORD event) {
	if (event == CTRL_CLOSE_EVENT) {
		closeRequested = true;
		//Sleep(20000);
		return TRUE;
	}
	return TRUE;
}

int main(int argc, char* argv[]) {
	SetConsoleCtrlHandler((PHANDLER_ROUTINE) (ctrl_handler), TRUE);

	Renderer* renderer = new Renderer(10000);
	renderer->Initialize();

	const char** playerGraph;
	playerGraph = new const char*[4];
	playerGraph[0] = " O ";
	playerGraph[1] = "-|-";
	playerGraph[2] = " | ";
	playerGraph[3] = "/ \\";
	Graphic* graph = new ArtGraphic(playerGraph, 3, 4);
	Entity* entity = new BouncingEntity(graph, {1, 1});
	entity->collider->layer = CollisionLayer::Enemy;
	entity->collider->layerMask = CollisionLayer::Decor;
	Entity* entity2 = new BouncingEntity(graph, {16, 8});
	entity2->collider->layer = CollisionLayer::Enemy;
	entity2->collider->layerMask = CollisionLayer::Decor;

	TextGraphic* statsTxt = new TextGraphic();
	Entity* stats = new Entity(statsTxt, {10, 0});

	Entity* colliderEnt = new Entity(graph, {10, 12}, true);
	colliderEnt->collider->layer = CollisionLayer::Decor;
	Entity* colliderEnt2 = new Entity(graph, { 50, 30 }, true);
	colliderEnt2->collider->layer = CollisionLayer::Decor;
	Entity* colliderEnt3 = new Entity(graph, { 30, 12 }, true);
	colliderEnt3->collider->layer = CollisionLayer::Decor;

	renderer->ResetFrameTimer();
	while (!closeRequested) {
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
