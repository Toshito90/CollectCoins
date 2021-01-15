#ifndef BASESCREEN_H
#define BASESCREEN_H

#include <SDL.h>
#include "ScreenManager.h"
#include "Application.h"

class BaseScreen {
protected:
	Application* game;
	ScreenManager* screens;
	SDL_Rect screen_rect;
	std::string screen_name;

public:
	virtual bool Init(Application* game, ScreenManager* screens) = 0;
	virtual void DynamicInput(InputManager* userinput) = 0;
	virtual void StaticInput(InputManager* userinput) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual SDL_Rect ScreenViewPort(int x, int y, int w, int h) = 0;
	virtual std::string GetScreenName() = 0;
	virtual void Quit() = 0;
};

#endif