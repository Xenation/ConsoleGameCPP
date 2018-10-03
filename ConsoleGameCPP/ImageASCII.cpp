#include "stdafx.h"
#include "ImageASCII.h"



ImageASCII::ImageASCII() {
}


bool ImageASCII::genererImage(std::string nomImage) {

	// on récup le nombres de lignes et de colonnes
	if (getNbLignesNbColonnes(nomImage)) {
		// on initialise la taille du tableau
		image = initialiserTableau(nb_colonnes, nb_lignes);
		remplirTableau(image, nomImage);
		return true;
	}
	else {
		std::cout << "l'image " << nomImage << " est introuvable." << std::endl;
		return false;
	}
}


bool ImageASCII::getNbLignesNbColonnes(std::string nomImage) {

	std::ifstream input(nomImage); //put your program together with thsi file in the same folder.
	if (input.is_open()) {

		while (!input.eof()) {

			std::string ligne;
			getline(input, ligne); //read number

			// on check si le texte possède bien un nombre de caracteres équivalent sur chaque ligne
			uniforme_ligne = (uniforme_ligne && (nb_colonnes == -1 && ligne.size() != 0) || ligne.size() == nb_colonnes);

			// on ne garde que la valeur de la colonnes la plus grande
			if(nb_colonnes < static_cast<int>(ligne.size())) nb_colonnes = ligne.size();

			nb_lignes++;
		}
		input.close();
		return true;
	}
	else {
		return false;
	}
}


char** ImageASCII::initialiserTableau(int col, int lign) {

	image = new char*[lign];
	for (int i = 0; i < lign; i++) {
		image[i] = new char[col];
	}

	return image;
}

void ImageASCII::remplirTableau(char **tableau, std::string nomImage) {

	std::ifstream input(nomImage); //put your program together with thsi file in the same folder.
	if (input.is_open()) {

		for (int i = 0; !input.eof(); i++) {

			std::string ligne;
			getline(input, ligne); //read line

			for (int j = 0; j < static_cast<int>(ligne.size()); j++) {
				tableau[i][j] = ligne[j];
			}
		}
		input.close();
	}
}

void ImageASCII::parcourirTableau(char **tableau) {

	for (int i = 0; i < nb_lignes; i++) {
		for (int j = 0; j < nb_colonnes; j++) {
			std::cout << tableau[i][j];
		}
		std::cout << std::endl;
	}
}

int ImageASCII::getWidth() const {
	return nb_colonnes;
}

int ImageASCII::getHeight() const {
	return nb_lignes;
}

char** ImageASCII::getImage() const {
	return image;
}


