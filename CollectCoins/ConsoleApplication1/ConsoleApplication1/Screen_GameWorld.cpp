#include "Screen_GameWorld.h"
#include "BaseScreen.h"

bool Screen_GameWorld::Init(Application* game, ScreenManager* screens) {
	this->game = game;
	this->screens = screens;

	screen_name = "Game World";

	filemanager = new FileManager(game);

	score = 0;

	font = new Font(game, filemanager->GetTexture("Data\\font_texture.png"), 16, 16, 8, 16);

	camera.Init(game, filemanager);

	screens->RemoveScreen("Intro Menu");

	return true;
}

void Screen_GameWorld::StaticInput(InputManager* userinput) {
	camera.StaticInput(userinput);
	for (int i = 0; i < TOTALKEYS; i++) {
		if (userinput->GetKey(i) == true) {
			if (userinput->GetActions(Action_BACK) == i)
				screens->PopScreen();
		}
	}
}

void Screen_GameWorld::DynamicInput(InputManager* userinput) {
	camera.DynamicInput(userinput);
}

void Screen_GameWorld::Update(float deltaTime) {
	camera.Update(deltaTime);
}

SDL_Rect Screen_GameWorld::ScreenViewPort(int x, int y, int w, int h) {
	if (w == 0)
		w = game->GetWindow_Width();
	if (h == 0)
		h = game->GetWindow_Height();

	screen_rect.x = x;
	screen_rect.y = y;
	screen_rect.w = w;
	screen_rect.h = h;

	return screen_rect;
}

void Screen_GameWorld::Render() {
	ScreenViewPort(0, 0, 0, 0);
	SDL_RenderSetViewport(game->GetRender(), &screen_rect);

	camera.Render();

	score = camera.GetUIScorePoints();
	char buffer[64];
	font->RenderString(0, 0, "Score: " + std::string(_itoa(score, buffer, 10)) + " Coins");
}

std::string Screen_GameWorld::GetScreenName() {
	return screen_name;
}

void Screen_GameWorld::Quit() {
	delete font;
	delete filemanager;

	camera.Quit();
}