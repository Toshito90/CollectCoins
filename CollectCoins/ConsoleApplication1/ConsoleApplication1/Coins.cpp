#include "Coins.h"
#include "Random.h"

void Coins::Init(Application* game, FileManager* filemanager) {
	this->game = game;
	this->filemanager = filemanager;

	sizeX = 16;
	sizeY = 16;

	texture = filemanager->GetTexture("Data\\item.png");

	PosX = 0;
	PosY = 0;

	camZoomX = 0;
	camZoomY = 0;

	coinPosX = 0;
	coinPosY = 0;

	Relocate();
}

void Coins::MoveMapCoins(float deltaTime, int PosX, int PosY, int camZoomX, int camZoomY) {
	this->PosX = PosX;
	this->PosY = PosY;
	this->camZoomX = camZoomX;
	this->camZoomY = camZoomY;

	Update(deltaTime, camZoomX, camZoomY);
}

void Coins::Update(float deltaTime, int camZoomX, int camZoomY) {
	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = sizeX;
	src_rect.h = sizeY;

	dst_rect.x = (coinPosX - PosX) * game->GetWindow_Width() / camZoomX;
	dst_rect.y = (coinPosY - PosY) * game->GetWindow_Height() / camZoomY;
	dst_rect.w = sizeX * game->GetWindow_Width() / camZoomX;
	dst_rect.h = sizeY * game->GetWindow_Height() / camZoomY;
}

void Coins::Render() {
	SDL_RenderCopy(game->GetRender(), texture, &src_rect, &dst_rect);
}

void Coins::Relocate() {
	x = Random::Int(4, 320 - 16 - 4);
	y = Random::Int(4, 240 - 16 - 4) + sizeY;

	//These numbers are here to define the correct location for drawing the Entities (in this case coins)
	coinPosX = x + 152;
	coinPosY = y + 112;
}