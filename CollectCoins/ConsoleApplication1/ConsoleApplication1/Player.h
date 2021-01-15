#ifndef PLAYER_H
#define PLAYER_H

#include "Entities.h"

class Player : public Entities {
private:
	float move_speed;

	SDL_Texture* sheet;

	float sheet_row, sheet_column, sheet_animSpeed;
	float dirX, dirY;

public:
	void Init(Application* game, FileManager* filemanager);
	void Update(float deltaTime, int camZoomX, int camZoomY);
	void Render();
	void Move(int dx, int dy);

	int GetPlayerX();
	int GetPlayerY();
};

#endif