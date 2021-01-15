#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <string>
#include <vector>
#include "InputManager.h"

class Application;
class BaseScreen;

class ScreenManager {
private:
	Application* game;
	std::vector<BaseScreen*> screens_stack;
	bool screenerror;
	bool IsStatic;

public:
	bool Init(Application* game);
	void Input(InputManager* userinput);
	void Update(float deltaTime);
	void Render();

	int GetNumScreens();
	void PushScreen(Application* game, BaseScreen* basescreen);
	void PopScreen();
	void RemoveScreen(std::string screen_name);
	bool ScreenError();
};

#endif