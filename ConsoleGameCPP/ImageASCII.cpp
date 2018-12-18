#include "stdafx.h"
#include "ImageASCII.h"



ImageASCII::ImageASCII() {
}


bool ImageASCII::GenerateImage(std::string nomImage) {

	// Get the line and column number
	if (GetLinesAndColumnsNumber(nomImage)) {
		// Initialize the size of the table
		image = InitializeTable(nbColumns, nbLines);
		FillTable(image, nomImage);
		return true;
	}
	else {
		std::cout << "l'image " << nomImage << " est introuvable." << std::endl;
		return false;
	}
}


bool ImageASCII::GetLinesAndColumnsNumber(std::string nomImage) {

	std::ifstream input(nomImage); //put your program together with this file in the same folder.
	if (input.is_open()) {

		while (!input.eof()) {

			std::string ligne;
			getline(input, ligne); //read number

			// Check that the file has the same number of characters on every line
			hasUniformLines = (hasUniformLines && (nbColumns == -1 && ligne.size() != 0) || ligne.size() == nbColumns);

			// Keep only the biggest column value
			if(nbColumns < static_cast<int>(ligne.size())) nbColumns = ligne.size();

			nbLines++;
		}
		input.close();
		return true;
	}
	else {
		return false;
	}
}


char** ImageASCII::InitializeTable(int col, int lign) {

	image = new char*[lign];
	for (int i = 0; i < lign; i++) {
		image[i] = new char[col];
	}

	return image;
}

void ImageASCII::FillTable(char **tableau, std::string nomImage) {

	std::ifstream input(nomImage); //put your program together with this file in the same folder.
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

void ImageASCII::SweepTable(char **tableau) {

	for (int i = 0; i < nbLines; i++) {
		for (int j = 0; j < nbColumns; j++) {
			std::cout << tableau[i][j];
		}
		std::cout << std::endl;
	}
}

int ImageASCII::GetWidth() const {
	return nbColumns;
}

int ImageASCII::GetHeight() const {
	return nbLines;
}

char** ImageASCII::GetImage() const {
	return image;
}


