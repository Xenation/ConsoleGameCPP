#pragma once
#include "ImageASCII.h"
#include "MathStructs.h"

class PlatformGenerator {


public :

	const char PLATFORM_ASCII_CODE = '=';
	const char PLATFORM_ASCII_REPRESENTATION = '_';
	const char PLAYER_ASCII_CODE = 'P';
	const char FREEZE_ASCII_CODE = 'F';
	const char SPEEDUP_ASCII_CODE = 'S';
	const char TRAP_ASCII_CODE = 'x';
	const char TRAP_ASCII_REPRESENTATION = 'X';

	void generateWorld(std::string nomFichierImage);
	Vec2i getPlayerInitialPosition();
	int getPlayerFreezeXPosition();
	int getPlayerSpeedUpXPosition();

private :
	Vec2i playerInitialPosition;
	int playerFreezeXPosition;
	int playerSpeedUpPosition;

};