#include "Font.h"

Font::Font(Application* game, SDL_Texture* sheet, int numcharsX, int numcharsY, int charWidth, int charHeight) {
	this->game = game;
	this->sheet = sheet;
	this->numcharsX = numcharsX;
	this->numcharsY = numcharsY;
	this->charWidth = charWidth;
	this->charHeight = charHeight;
}

void Font::RenderChar(float x, float y, unsigned char data) {
	//src_rect = Source Rectangle and dst_rect = Destination Rectangle
	SDL_Rect src_rect, dst_rect;

	src_rect.x = (data % numcharsX) * charWidth;
	src_rect.y = (data / numcharsY) * charHeight;
	src_rect.w = charWidth;
	src_rect.h = charHeight;

	dst_rect.x = x * game->GetWindow_Width() / WINDOW_WIDTH_ORIGINAL;
	dst_rect.y = y * game->GetWindow_Height() / WINDOW_HEIGHT_ORIGINAL;
	dst_rect.w = charWidth * game->GetWindow_Width() / WINDOW_WIDTH_ORIGINAL;
	dst_rect.h = charHeight * game->GetWindow_Height() / WINDOW_HEIGHT_ORIGINAL;

	SDL_RenderCopy(game->GetRender(), sheet, &src_rect, &dst_rect);
}

void Font::RenderString(float x, float y, std::string data) {
	for (int i = 0; i < data.length(); i++)
		RenderChar(x + i * charWidth, y, data.at(i));
}