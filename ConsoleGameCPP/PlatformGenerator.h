#pragma once
#include "ImageASCII.h"
#include "MathStructs.h"

class PlatformGenerator {


public :

	const char PLATFORM_ASCII_CODE = '=';
	const char PLATFORM_ASCII_REPRESENTATION = '=';

	void generateWorld(std::string nomFichierImage);


private :

	const char** genererGraph(int taille);

};