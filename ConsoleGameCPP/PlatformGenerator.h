#pragma once
#include "ImageASCII.h"
#include "MathStructs.h"

class PlatformGenerator {


public :

	const char PLATFORM_ASCII_CODE = '=';
	const char PLATFORM_ASCII_REPRESENTATION = '_';
	const char PLAYER_ASCII_CODE = 'P';
	const char TRAP_ASCII_CODE = 'x';
	const char TRAP_ASCII_REPRESENTATION = '^';

	void generateWorld(std::string nomFichierImage);
	Vec2i getPlayerInitialPosition();

private :
	Vec2i playerInitialPosition;

};