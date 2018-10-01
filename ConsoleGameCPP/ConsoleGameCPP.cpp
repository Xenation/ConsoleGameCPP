// ConsoleGameCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Windows.h"

#include "Graphic.h"
#include "Constants.h"
#include "Entity.h"
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
}

int main(int argc, char* argv[]) {
	SetConsoleCtrlHandler((PHANDLER_ROUTINE) (ctrl_handler), TRUE);

	Renderer* renderer = new Renderer(30);
	renderer->Initialize();

	const char** playerGraph;
	playerGraph = new const char*[4];
	playerGraph[0] = " O ";
	playerGraph[1] = "-|-";
	playerGraph[2] = " | ";
	playerGraph[3] = "/ \\";
	Graphic* graph = new Graphic(playerGraph, 3, 4);
	Entity* entity = new Entity(graph, {1, 1});
	Entity* entity2 = new Entity(graph, {8, 8});

	renderer->ResetFrameTimer();
	while (!closeRequested) {
		// Update
		EntityManager::getInstance().UpdateAllEntities();

		// Render
		renderer->Render();

		renderer->EndFrame();

		renderer->ClearBuffer(); // TODO maybe replace by buffer swap method
	}

	return 0;
}
