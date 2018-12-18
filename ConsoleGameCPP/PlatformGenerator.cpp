#include "stdafx.h"
#include "PlatformGenerator.h"
#include "Entity.h"
#include "Collider.h"
#include "CollisionLayer.h"
#include "Graphic.h"
#include "ArtGraphic.h"
#include "GraphicRender.h"
#include "RenderLayer.h"


void PlatformGenerator::GenerateWorld(std::string imageFileName) {
	 
	ImageASCII *img = new ImageASCII();

	if (img->GenerateImage(imageFileName)) {

		char **charImg = img->GetImage();

		// Indicates the start of a platform
		// Resets for each new platform
		Vec2i posPlatform = { 0, 0 };

		// Indicates whether or not a platform is being constructed
		// Resets for each new platform
		bool ongoingConstruction = false;

		bool ongoingTrapConstruction = false;

		// Indicates the horizontal size of the platform
		// Resets for each new platform
		int platformSize = 0;


		for (int i = 0; i < img->GetHeight(); i++) {
			for (int j = 0; j < img->GetWidth(); j++) {

		/****** GET THE PLAYER INITIAL POSITION ******/

				if (charImg[i][j] == PLAYER_ASCII_CODE) {
					playerInitialPosition = { j, i };
				}

		/****** GET THE FREEZE CAMERA POSITION ******/

				if (charImg[i][j] == FREEZE_ASCII_CODE) {
					playerFreezeXPosition = j;
				}

		/****** GET THE SPEED UP POSITION ******/

				if (charImg[i][j] == SPEEDUP_ASCII_CODE) {
					playerSpeedUpPosition = j;
				}

		/****** GET THE END POSITION ******/

				if (charImg[i][j] == END_ASCII_CODE) {
					playerEndPosition = j;
				}


		/****** GENERATE PLATFORMS ******/

				// If a platform is being constructed
				// If the current character is part of this platform
				if ((ongoingConstruction && charImg[i][j] == PLATFORM_ASCII_CODE) || (ongoingTrapConstruction && charImg[i][j] == TRAP_ASCII_CODE)) {
					platformSize++;

				// Else, this means we are at the end of the platform
				} else {

					// So, we create it entity
					wchar_t** platformGraph = new wchar_t*[1];
					platformGraph[0] = new wchar_t[platformSize];

					// If it's a platform, we create a platform
					if (ongoingConstruction) {
						std::fill_n(platformGraph[0], platformSize, PLATFORM_ASCII_REPRESENTATION);

						Graphic* graph = new ArtGraphic(platformGraph, platformSize, 1);
						graph->backgroundColor = ConsoleColor::BRIGHT_BLACK;
						Entity* colliderEnt3 = new Entity(graph, posPlatform, true);
						colliderEnt3->GetGraphicRender()->SetLayer(RenderLayer::Decor);
						colliderEnt3->GetCollider()->SetLayer(&CollisionLayer::Decor);

						ongoingConstruction = false;

					}

					// If it's a trap, we create a trap
					if (ongoingTrapConstruction) {
						std::fill_n(platformGraph[0], platformSize, TRAP_ASCII_REPRESENTATION);

						Graphic* graph = new ArtGraphic(platformGraph, platformSize, 1);
						Entity* colliderEnt3 = new Entity(graph, posPlatform, true);
						colliderEnt3->GetGraphicRender()->SetLayer(RenderLayer::Decor);
						colliderEnt3->GetCollider()->SetLayer(&CollisionLayer::Trap);
						ongoingTrapConstruction = false;

					}
					
					
				}

				// Starting the construction and initializing it
				if (charImg[i][j] == PLATFORM_ASCII_CODE && !ongoingConstruction) {
					ongoingConstruction = true;
					platformSize = 0;
					posPlatform = { j, i };
				}

				if (charImg[i][j] == TRAP_ASCII_CODE && !ongoingTrapConstruction) {
					ongoingTrapConstruction = true;
					platformSize = 0;
					posPlatform = { j, i };
				}
			}

		}

	} else {
		std::cout << "Image not found!" << std::endl;
	}

}



Vec2i PlatformGenerator::GetPlayerInitialPosition() const {
	return playerInitialPosition;
}

int PlatformGenerator::GetPlayerFreezeXPosition() const {
	return playerFreezeXPosition;
}

int PlatformGenerator::GetPlayerSpeedUpXPosition() const {
	return playerSpeedUpPosition;
}

int PlatformGenerator::GetPlayerEndXPosition() const {
	return playerEndPosition;
}