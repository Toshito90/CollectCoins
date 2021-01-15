#ifndef CAMERA_H
#define CAMERA_H

#include "Application.h"
#include "Player.h"
#include "Entities.h"
#include "Coins.h"
#include "GameMap.h"

enum CameraModeTarget {
	None,
	Character,
	NPC
};

class Camera {
private:
	Application* game;
	InputManager* userinput;

	int camX, camY;
	int cam_zoomX, cam_zoomY;

	Player player;

	std::vector<Coins*> coins;

	GameMap* game_map;

	int score;

public:
	void Init(Application* game, FileManager* filemanager);
	void CameraTarget(int camtarget);
	void Zoom(int zoomX, int zoomY);
	void DynamicInput(InputManager* userinput);
	void StaticInput(InputManager* userinput);
	void Render();
	void Update(float deltaTime);
	void Quit();

	int GetUIScorePoints();
};

#endif