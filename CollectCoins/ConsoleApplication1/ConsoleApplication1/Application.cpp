#include "Application.h"
#include "CleanUP.h"

Application::Application() {
	window = NULL;
	render = NULL;

	window_width = 1024;
	window_height = 800;

	oldTime = 0;

	quit = false;
}

void Application::ErrorLog(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

bool Application::Init() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		ErrorLog(std::cout, "SDL_Init: ");
		return false;
	}

	window = SDL_CreateWindow("Quest Project!",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height,
		SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		ErrorLog(std::cout, "SDL_CreateWindow: ");
		return false;
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (render == NULL) {
		ErrorLog(std::cout, "SDL_CreateRenderer: ");
		return false;
	}

	if (screens.Init(this) == false) {
		std::cout << "Error on Initializing the ScreenManager." << std::endl;
		return false;
	}
	if (userinput.Init(this) == false) {
		std::cout << "Error Loading the InputManager." << std::endl;
		return false;
	}

	srand(time(NULL));

	return true;
}

void Application::Thread() {
	while (!quit) {
		Input();
		Update();
		Render();
	}

	Quit();
}

void Application::Update() {
	oldTime = newTime;
	newTime = SDL_GetTicks();

	if (newTime > oldTime) {
		float deltaTime = (float)(newTime - oldTime) / 1000.0f;

		if (screens.ScreenError())
			SetQuit();

		screens.Update(deltaTime);
	}
}

void Application::Render() {
	SDL_RenderClear(render);

	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);

	screens.Render();
	SDL_RenderPresent(render);
}

void Application::Quit() {

	if (screens.GetNumScreens() > 0) {
		for (int i = 0; i < screens.GetNumScreens(); i++) {
			screens.PopScreen();
		}
	}

	CleanUP(render, window);
	SDL_Quit();
}

void Application::Input() {
	//userinput.Check_Input();
	screens.Input(&userinput);

	window_width = userinput.CheckWindowWidth();
	window_height = userinput.CheckWindowHeight();
}

int Application::GetWindow_Width() {
	return window_width;
}
int Application::GetWindow_Height() {
	return window_height;
}

SDL_Renderer* Application::GetRender() {
	return render;
}

void Application::SetQuit() {
	quit = true;
}