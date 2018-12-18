#pragma once
#include <string>
#include <iostream>
#include<fstream>

/*
===============================================================================
Class that reads a text file and creates an image
===============================================================================
*/
class ImageASCII {

public: 
	
	ImageASCII(); // Constructor

	bool GenerateImage(std::string nomImg); // To be called before the other methods

	void SweepTable(char **tableau); // Needed for debug

	// Accessors
	int GetWidth() const;
	int GetHeight() const;
	char** GetImage() const;

private:

	int nbLines = 0; // Number of lines of the file

	int nbColumns = -1; // Number of colums of the file

	bool hasUniformLines = true; // Flag indicating whether or not the file has the same number of characters on every line

	char** image = nullptr;

	std::string imageName;

	bool GetLinesAndColumnsNumber(std::string nomImg);

	char **InitializeTable(int col, int lign);

	void FillTable(char **tableau, std::string nomImage);

};