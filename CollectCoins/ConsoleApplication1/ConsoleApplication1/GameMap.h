#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "FileManager.h"
#include "Application.h"

#define TILESIZE 16
#define MAPWIDTH 20
#define MAPHEIGHT 15

class GameMap {
private:
	SDL_Texture* tile;

	Application* game;
	FileManager* filemanager;

	SDL_Rect screen_rect;

	int Map_PosX, Map_PosY;
	int Map_Height, Map_Width;

public:
	GameMap(Application* game, FileManager* filemanager);

	void Init();
	SDL_Rect ScreenViewport(int x, int y, int w, int h);
	void Render(int PosX, int PosY, int camZoomX, int camZoomY);
};

#endif