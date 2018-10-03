#pragma once
#include <string>
#include <iostream>
#include<fstream>





class ImageASCII {

public: 
	
	//constructeur
	ImageASCII();

	// A APPELER OBLIGATOIREMENT AVANT TOUT AUTRE FONCTION DE LA CLASSE
	bool genererImage(std::string nomImg);

	// debug only
	void parcourirTableau(char **tableau);

	// retourne le nombre de colonnes de l'image
	int getWidth() const;

	// retourne le nombre de lignes de l'image
	int getHeight() const;

	// retourne l'image
	char** getImage() const;

private:

	// le nombre de lignes possédées par le fichier
	int nb_lignes = 0;

	//le nombre de colonnes possédées par le fichier
	int nb_colonnes = -1;

	// flag indiquant si le fichier possède le même nombre de caractères sur chaque ligne
	bool uniforme_ligne = true;

	char** image = nullptr;

	std::string nomImage;

	bool getNbLignesNbColonnes(std::string nomImg);

	char **initialiserTableau(int col, int lign);

	void remplirTableau(char **tableau, std::string nomImage);

};