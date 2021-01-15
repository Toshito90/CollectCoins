#include "ScreenManager.h"
#include "BaseScreen.h"
#include "Screen_IntroMenu.h"
#include "Application.h"

bool ScreenManager::Init(Application* game) {
	this->game = game;
	screenerror = false;
	IsStatic = false;

	PushScreen(game, new Screen_IntroMenu());

	return true;
}

void ScreenManager::Input(InputManager* userinput) {
	if (screens_stack.size() > 0) {
		userinput->Check_Input();

		if (!IsStatic) {
			screens_stack.back()->StaticInput(userinput);
			IsStatic = true;
		}
		if (!userinput->GetKeyPressedState())
			IsStatic = false;

		for (int i = 0; i < screens_stack.size(); i++) {
			screens_stack.at(i)->DynamicInput(userinput);
		}
	}
}

void ScreenManager::Render() {
	if (screens_stack.size() > 0) {
		for (int i = 0; i < screens_stack.size(); i++) {
			screens_stack.at(i)->Render();
		}
	}
}

void ScreenManager::Update(float deltaTime) {
	if (screens_stack.size() > 0) {
		for (int i = 0; i < screens_stack.size(); i++) {
			screens_stack.at(i)->Update(deltaTime);
		}
	}
}

int ScreenManager::GetNumScreens() {
	return screens_stack.size();
}

void ScreenManager::PushScreen(Application* game, BaseScreen* screen) {
	screens_stack.push_back(screen);

	if (screen->Init(game, this) == false)
		screenerror = true;
}

void ScreenManager::PopScreen() {
	screens_stack.back()->Quit();

	delete screens_stack.back();
	screens_stack.pop_back();

	if (screens_stack.size() <= 0)
		game->SetQuit();
}

void ScreenManager::RemoveScreen(std::string screen_name) {
	std::string rscreen;
	for (int index = 0; index < screens_stack.size(); index++) {
		rscreen = screens_stack.at(index)->GetScreenName();
		if (rscreen == screen_name) {
			screens_stack.at(index)->Quit();
			screens_stack.erase(screens_stack.begin() + index);
		}
	}
}

bool ScreenManager::ScreenError() {
	return screenerror;
}