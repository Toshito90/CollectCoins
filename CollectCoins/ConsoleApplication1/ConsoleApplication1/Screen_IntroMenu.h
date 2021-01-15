#ifndef SCREEN_INTROMENU_H
#define SCREEN_INTROMENU_H

#include "BaseScreen.h"
#include "FileManager.h"
#include "Font.h"
#include "Screen_GameWorld.h"

class Screen_IntroMenu : public BaseScreen {
private:
	FileManager* filemanager;

	Font* font;

	float blinking;

	SDL_Texture* texture;

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