#include "Player.h"

void Player::Init(Application* game, FileManager* filemanager) {
	this->game = game;
	this->filemanager = filemanager;

	sizeX = 16;
	sizeY = 32;

	x = 160 - (sizeX / 2);
	y = 144 - (sizeY / 2);

	dirX = 0.0f;
	dirY = 0.0f;

	sheet_row = 0.0f;
	sheet_column = 0.0;
	sheet_animSpeed = 6.0f;

	move_speed = 32.0f;

	sheet = filemanager->GetTexture("Data\\character.png");
}

void Player::Update(float deltaTime, int camZoomX, int camZoomY) {
	if (dirX != 0 || dirY != 0) {
		sheet_row += sheet_animSpeed * deltaTime;
		if ((int)sheet_row >= 4)
			sheet_row = 0.0f;
	}
	else {
		sheet_row = 0.0f;
	}

	if (dirX > 0)
		sheet_column = 3;
	if (dirX < 0)
		sheet_column = 2;
	if (dirY < 0)
		sheet_column = 1;
	if (dirY > 0)
		sheet_column = 0;

	x += dirX * move_speed * deltaTime;
	y += dirY * move_speed * deltaTime;

	src_rect.x = sizeX * (int)sheet_column;
	src_rect.y = sizeY * (int)sheet_row;
	src_rect.w = sizeX;
	src_rect.h = sizeY;


	//These Magic Numbers here is just for position correctly the character when Zooming In and Zooming Out the Camera
	dst_rect.x = (160 - (sizeX / 2)) * game->GetWindow_Width() / camZoomX;
	dst_rect.y = (128 - (sizeY / 2)) * game->GetWindow_Height() / camZoomY;
	dst_rect.w = sizeX * game->GetWindow_Width() / camZoomX;
	dst_rect.h = sizeY * game->GetWindow_Height() / camZoomY;

	dirX = 0.0f;
	dirY = 0.0f;
}

void Player::Render() {
	SDL_RenderCopy(game->GetRender(), sheet, &src_rect, &dst_rect);
}

void Player::Move(int dx, int dy) {
	dirX += dx;
	dirY += dy;
}

int Player::GetPlayerX() {
	return (int)x;
}

int Player::GetPlayerY() {
	return (int)y;
}