#include "stdafx.h"
#include "PlatformGenerator.h"
#include "Entity.h"
#include "Collider.h"
#include "CollisionLayer.h"
#include "Graphic.h"
#include "ArtGraphic.h"
#include "GraphicRender.h"
#include "RenderLayer.h"


void PlatformGenerator::generateWorld(std::string nomFichierImage) {
	 
	ImageASCII *img = new ImageASCII();

	if (img->genererImage(nomFichierImage)) {

		char **charImg = img->getImage();

		// indique le début de la plateforme
		// variable reset à chaque nouveelle platforme
		Vec2i posPlatform = { 0, 0 };

		// indique si le programme est en train de contruire une plateforme
		// variable reset à chaque nouvelle platforme
		bool enConstruction = false;

		bool trapEnConstruction = false;

		// indique la taille de la plateforme (à l'horizontale)
		// variable reset à chaque nouvelle platforme
		int taillePlateform = 0;


		for (int i = 0; i < img->getHeight(); i++) {
			for (int j = 0; j < img->getWidth(); j++) {

		/****** RECUPERATION DE LA POSITION DU JOUEUR ******/

				if (charImg[i][j] == PLAYER_ASCII_CODE) {
					playerInitialPosition = { j, i };
				}

		/****** RECUPERATION DE LA POSITION DU JOUEUR ******/

				if (charImg[i][j] == FREEZE_ASCII_CODE) {
					playerFreezeXPosition = j;
				}


		/****** GENERATION DES PLATEFORMES ******/


				// si on est en construction d'une plateforme
				// si le caractere en cours est un caractere de la plateforme
				if ((enConstruction && charImg[i][j] == PLATFORM_ASCII_CODE) || (trapEnConstruction && charImg[i][j] == TRAP_ASCII_CODE)) {
					taillePlateform++;

				// sinon, ça veut dire que nous sommes à la fin de la plateforme
				} else {

					// on créé donc l'entity de celle-ci
					char** platformGraph = new char*[1];
					platformGraph[0] = new char[taillePlateform];

					// si c'est une plateforme, on génère une plateforme
					if (enConstruction) {
						std::fill_n(platformGraph[0], taillePlateform, PLATFORM_ASCII_REPRESENTATION);

						Graphic* graph = new ArtGraphic(platformGraph, taillePlateform, 1);
						Entity* colliderEnt3 = new Entity(graph, posPlatform, true);
						colliderEnt3->graphicRender->setLayer(RenderLayer::Decor);
						colliderEnt3->collider->layer = &CollisionLayer::Decor;

						enConstruction = false;

					}

					// si c'est un piege, on génère un piège
					if (trapEnConstruction) {
						std::fill_n(platformGraph[0], taillePlateform, TRAP_ASCII_REPRESENTATION);

						Graphic* graph = new ArtGraphic(platformGraph, taillePlateform, 1);
						Entity* colliderEnt3 = new Entity(graph, posPlatform, true);
						colliderEnt3->graphicRender->setLayer(RenderLayer::Decor);
						colliderEnt3->collider->layer = &CollisionLayer::Enemy;
						trapEnConstruction = false;

					}
					
					
				}

				// début de la construction, initialisation de celle-ci
				if (charImg[i][j] == PLATFORM_ASCII_CODE && !enConstruction) {
					enConstruction = true;
					taillePlateform = 0;
					posPlatform = { j, i };
				}

				if (charImg[i][j] == TRAP_ASCII_CODE && !trapEnConstruction) {
					trapEnConstruction = true;
					taillePlateform = 0;
					posPlatform = { j, i };
				}
			}

		}

	} else {
		std::cout << "image non trouvée" << std::endl;
	}

}



Vec2i PlatformGenerator::getPlayerInitialPosition() {
	return playerInitialPosition;
}

int PlatformGenerator::getPlayerFreezeXPosition() {
	return playerFreezeXPosition;
}