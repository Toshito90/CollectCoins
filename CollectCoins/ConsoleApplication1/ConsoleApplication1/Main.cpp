#include <SDL.h>
#include "Application.h"

int main(int argc, char* args[])
{
	Application game;

	if (game.Init())
		game.Thread();

	getchar();
	return 0;
}

