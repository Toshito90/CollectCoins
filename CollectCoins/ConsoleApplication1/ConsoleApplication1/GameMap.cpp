#include "GameMap.h"

GameMap::GameMap(Application* game, FileManager* filemanager) {
	this->game = game;
	this->filemanager = filemanager;
	tile = NULL;
}

void GameMap::Init() {
	tile = filemanager->GetTexture("Data\\tile_01.png");

	Map_PosX = 152 / TILESIZE;
	Map_PosY = 120 / TILESIZE;

	Map_Height = Map_PosY + 15;
	Map_Width = Map_PosX + 20;
}

SDL_Rect GameMap::ScreenViewport(int x, int y, int w, int h) {
	if (w == 0)
		w = game->GetWindow_Width();
	if (h == 0)
		h = game->GetWindow_Height();

	screen_rect.x = x;
	screen_rect.y = y;
	screen_rect.w = w;
	screen_rect.h = h;

	return screen_rect;
}

void GameMap::Render(int PosX, int PosY, int camZoomX, int camZoomY) {

	Map_Height = Map_PosY + 15;
	Map_Width = Map_PosX + 20;

	for (int y = Map_PosY; y < Map_Height; y++) {
		for (int x = Map_PosX; x < Map_Width; x++) {
			SDL_Rect rect;

			//For now there is these magic numbers to define the half of the value for each Character's Width and Height
			rect.x = ((x * TILESIZE - PosX) + (TILESIZE / 2)) * game->GetWindow_Width() / camZoomX;
			rect.y = ((y * TILESIZE - PosY) + TILESIZE) * game->GetWindow_Height() / camZoomY;
			rect.w = TILESIZE * game->GetWindow_Width() / camZoomX + 1;
			rect.h = TILESIZE * game->GetWindow_Height() / camZoomY + 1;

			SDL_RenderCopy(game->GetRender(), tile, NULL, &rect);
		}
	}
}