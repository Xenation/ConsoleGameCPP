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

using namespace std;

void clearBuffer(CHAR_INFO* buffer, int width, int height) {
	for (int i = 0; i < width * height; i++) {
		buffer[i] = {};
	}
}

int main(int argc, char* argv[]) {

	HANDLE hOutput = (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

	const char** playerGraph;
	playerGraph = new const char*[4];
	playerGraph[0] = " O ";
	playerGraph[1] = "-|-";
	playerGraph[2] = " | ";
	playerGraph[3] = "/ \\";
	Graphic* graph = new Graphic(playerGraph, 3, 4);
	Entity* entity = new Entity(graph, {1, 1});
	Entity* entity2 = new Entity(graph, { 8, 8 });

	while (true) {
		// Update
		EntityManager::getInstance().UpdateAllEntities();

		// Render
		EntityManager::getInstance().RenderAllEntities(buffer);

		// Write to console
		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);

		Sleep(20);

		// Clear Buffer
		clearBuffer(*buffer, SCREEN_WIDTH, SCREEN_HEIGHT);

	}

	return 0;
}
