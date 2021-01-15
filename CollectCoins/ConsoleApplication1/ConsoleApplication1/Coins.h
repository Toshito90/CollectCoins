#ifndef COINS_H
#define COINS_H

#include "Entities.h"

class Coins : public Entities {
private:
	SDL_Texture* texture;
	int PosX, PosY;
	int camZoomX, camZoomY;
	int coinPosX, coinPosY;

public:
	void Init(Application* game, FileManager* filemanager);
	void MoveMapCoins(float deltaTime, int PosX, int PosY, int camZoomX, int camZoomY);
	void Update(float deltaTime, int camZoomX, int camZoomY);
	void Render();

	void Relocate();
};

#endif