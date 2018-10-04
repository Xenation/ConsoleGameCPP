#pragma once
#include "ImageASCII.h"
#include "MathStructs.h"

class PlatformGenerator {


public :

	const char PLATFORM_ASCII_CODE = '=';
	const char PLATFORM_ASCII_REPRESENTATION = 'O';

	const char PLAYER_ASCII_CODE = 'P';


	void generateWorld(std::string nomFichierImage);
	Vec2i getPlayerInitialPosition();

private :
	Vec2i playerInitialPosition;

};