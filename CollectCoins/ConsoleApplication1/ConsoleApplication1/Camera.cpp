#include "Camera.h"
#include <stdio.h>

void Camera::Init(Application* game, FileManager* filemanager) {
	this->game = game;

	game_map = new GameMap(game, filemanager);
	game_map->Init();

	for (int i = 0; i < 20; i++) {
		coins.push_back(new Coins());
		coins.back()->Init(game, filemanager);
	}

	player.Init(game, filemanager);

	camX = player.GetPlayerX();
	camY = player.GetPlayerY();

	//These values are here to define the original Zooming Size of the camera, this is a place-holder, 
	//it will be replaced once there is a function to load configurations about the camera
	cam_zoomX = 320;
	cam_zoomY = 240;

	score = 0;
}

void Camera::CameraTarget(int camtarget) {

}

void Camera::Zoom(int zoomX, int zoomY) {
	cam_zoomX = zoomX;
	cam_zoomY = zoomY;
}

void Camera::DynamicInput(InputManager* userinput) {
	for (int i = 0; i < TOTALKEYS; i++) {
		if (userinput->GetKey(i) == true) {
			if (userinput->GetActions(Action_PlayerMOVEUP) == i)
				player.Move(0, -1);
			if (userinput->GetActions(Action_PlayerMOVEDOWN) == i)
				player.Move(0, 1);
			if (userinput->GetActions(Action_PlayerMOVELEFT) == i)
				player.Move(-1, 0);
			if (userinput->GetActions(Action_PlayerMOVERIGHT) == i)
				player.Move(1, 0);
		}
	}
}

void Camera::StaticInput(InputManager* userinput) {
	for (int i = 0; i < TOTALKEYS; i++) {
		if (userinput->GetKey(i) == true) {
			if (userinput->GetActions(Action_CamZoomIn) == i)
				Zoom(cam_zoomX / 2, cam_zoomY / 2);
			if (userinput->GetActions(Action_CamZoomOut) == i)
				Zoom(cam_zoomX * 2, cam_zoomY * 2);
		}
	}
}

void Camera::Render() {

	game_map->Render(camX, camY, cam_zoomX, cam_zoomY);

	for(int i = 0; i < coins.size(); i++){
		coins.at(i)->Render();
	}

	player.Render();
}

void Camera::Update(float deltaTime) {
	player.Update(deltaTime, cam_zoomX, cam_zoomY);

	camX = player.GetPlayerX();
	camY = player.GetPlayerY();

	//The logic of the coins needs to be ported to another file, since it doesn't belong here.
	for (int i = 0; i < coins.size(); i++) {
		coins.at(i)->MoveMapCoins(deltaTime, camX, camY, cam_zoomX, cam_zoomY);
		if (coins.at(i)->CollidesWith(&player)) {
			coins.at(i)->Relocate();
			score++;
		}
	}
}

void Camera::Quit() {

	for (int i = 0; i < coins.size(); i++) {
		delete coins.at(i);
	}

	coins.clear();
}

int Camera::GetUIScorePoints() {
	return score;
}