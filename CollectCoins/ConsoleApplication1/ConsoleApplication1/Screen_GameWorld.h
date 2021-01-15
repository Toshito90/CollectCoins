#ifndef SCREEN_GAMEWORLD_H
#define SCREEN_GAMEWORLD_H

#include "BaseScreen.h"
#include "FileManager.h"
#include "Font.h"
#include "Camera.h"

class Screen_GameWorld : public BaseScreen {
private:
	FileManager* filemanager;

	Font* font;

	Camera camera;

	int score;

public:
	bool Init(Application* game, ScreenManager* screens);
	void DynamicInput(InputManager* userinput);
	void StaticInput(InputManager* userinput);
	void Update(float deltaTime);
	void Render();
	SDL_Rect ScreenViewPort(int x, int y, int w, int h);
	std::string GetScreenName();
	void Quit();
};

#endif