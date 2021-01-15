#ifndef FONT_H
#define FONT_H

#include "Application.h"

class Font {
private:
	Application* game;
	SDL_Texture* sheet;

	int numcharsX, numcharsY, charWidth, charHeight;

public:
	Font(Application* game, SDL_Texture* sheet, int numcharsX, int numcharsY,
		int charWidth, int charHeight);

	void RenderChar(float x, float y, unsigned char data);

	void RenderString(float x, float y, std::string data);
};

#endif