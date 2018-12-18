#pragma once
#include "ImageASCII.h"
#include "MathStructs.h"

/*
===============================================================================
Class that generates the terrain of the game
===============================================================================
*/
class PlatformGenerator {

public :

	// Characters used in the file and representation in game
	const char PLATFORM_ASCII_CODE = '=';
	const wchar_t PLATFORM_ASCII_REPRESENTATION = L'▓';
	const char PLAYER_ASCII_CODE = 'P';
	const char FREEZE_ASCII_CODE = 'F';
	const char SPEEDUP_ASCII_CODE = 'S';
	const char TRAP_ASCII_CODE = 'x';
	const wchar_t TRAP_ASCII_REPRESENTATION = L'X';
	const char END_ASCII_CODE = 'E';

	void GenerateWorld(std::string imageFileName); // Creates the terrain and platforms

	// Accessors
	Vec2i GetPlayerInitialPosition() const;
	int GetPlayerFreezeXPosition() const;
	int GetPlayerSpeedUpXPosition() const;
	int GetPlayerEndXPosition() const;

private :
	Vec2i playerInitialPosition;
	int playerFreezeXPosition;
	int playerSpeedUpPosition;
	int playerEndPosition;

};