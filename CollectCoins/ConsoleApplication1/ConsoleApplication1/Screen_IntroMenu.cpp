#include "Screen_IntroMenu.h"
#include "BaseScreen.h"

bool Screen_IntroMenu::Init(Application* game, ScreenManager* screens) {
	this->game = game;
	this->screens = screens;

	screen_name = "Intro Menu";

	filemanager = new FileManager(game);

	font = new Font(game, filemanager->GetTexture("Data\\font_texture.png"), 16, 16, 8, 16);
	texture = filemanager->GetTexture("Data\\Exclamation Point.png");

	blinking = 0.0f;

	return true;
}

void Screen_IntroMenu::StaticInput(InputManager* userinput) {
	for (int i = 0; i < TOTALKEYS; i++) {
		if (userinput->GetKey(i) == true) {
			if (userinput->GetActions(Action_START) == i)
				screens->PushScreen(game, new Screen_GameWorld());
			if (userinput->GetActions(Action_BACK) == i)
				screens->PopScreen();
		}
	}
}

void Screen_IntroMenu::DynamicInput(InputManager* userinput) {

}

void Screen_IntroMenu::Update(float deltaTime) {
	blinking += 2 * deltaTime;

	if (blinking >= 2.0f)
		blinking = 0.0f;
}

SDL_Rect Screen_IntroMenu::ScreenViewPort(int x, int y, int w, int h) {
	if (w <= 0)
		w = game->GetWindow_Width();
	if (h <= 0)
		h = game->GetWindow_Height();

	screen_rect.x = x;
	screen_rect.y = y;
	screen_rect.w = w;
	screen_rect.h = h;

	return screen_rect;
}

void Screen_IntroMenu::Render() {
	SDL_SetRenderDrawColor(game->GetRender(), 0, 0, 0, 255);
	ScreenViewPort(0, 0, 0, 0);
	SDL_RenderFillRect(game->GetRender(), &screen_rect);
	SDL_RenderSetViewport(game->GetRender(), &screen_rect);

	SDL_RenderCopy(game->GetRender(), texture, NULL, NULL);

	std::string text = "Press ENTER to start!!!!";

	float x = (int)text.length() * 8 / 2;

	if ((int)blinking > 0)
		font->RenderString(160 - x, 140, text);

	text = "Welcome to Quest Project!";

	x = text.length() * 8 / 2;

	font->RenderString(160 - x, 32, text);
}

std::string Screen_IntroMenu::GetScreenName() {
	return screen_name;
}

void Screen_IntroMenu::Quit() {
	delete font;
	delete filemanager;
}