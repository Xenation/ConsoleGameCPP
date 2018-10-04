#pragma once
class TextGraphic : public Graphic {
public:
	TextGraphic();
	TextGraphic(const char* text);
	~TextGraphic();
	void setText(const char* text);
	char* getText();
};

