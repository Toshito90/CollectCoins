#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <SDL.h>
#include <iostream>
#include <time.h>
#include "ScreenManager.h"
#include "InputManager.h"

#define WINDOW_WIDTH_ORIGINAL 320
#define WINDOW_HEIGHT_ORIGINAL 240

class Application {
private:
	SDL_Window* window;
	SDL_Renderer* render;
	int window_width, window_height;
	Uint32 newTime, oldTime;
	bool quit;
	ScreenManager screens;
	InputManager userinput;

public:
	Application();
	void ErrorLog(std::ostream &os, const std::string &msg);
	bool Init();
	void Thread();

private:
	void Input();
	void Update();
	void Render();
	void Quit();

public:
	SDL_Renderer* GetRender();
	void SetQuit();
	int GetWindow_Width();
	int GetWindow_Height();
};

#endif