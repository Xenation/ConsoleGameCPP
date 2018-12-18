#pragma once

/*
===============================================================================
Class used for the text
===============================================================================
*/
class TextGraphic : public Graphic {
public:
	TextGraphic();
	TextGraphic(const char* text);
	~TextGraphic();

	// Accessor and mutator
	char* GetText() const;
	void SetText(const char* text);
};

