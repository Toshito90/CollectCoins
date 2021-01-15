#include "FileManager.h"
#include "Application.h"
#include "CleanUP.h"

FileManager::FileManager(Application* game) {
	this->game = game;
}

SDL_Texture* FileManager::GetTexture(std::string filename) {
	SDL_Texture* texture = NULL;

	//resPath means Resource Path and it is responsible to get the Base Path address of the application
	std::string resPath = SDL_GetBasePath();

	filename = resPath + filename;

	texture = IMG_LoadTexture(game->GetRender(), filename.c_str());

	if (texture == NULL) {
		std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
		game->SetQuit();
	}

	textures.insert(std::pair<std::string, SDL_Texture*>(filename, texture));

	std::map<std::string, SDL_Texture*>::iterator i;

	i = textures.find(filename);

	texture = i->second;

	return texture;
}

FileManager::~FileManager() {
	std::map<std::string, SDL_Texture*>::iterator i;

	for (i = textures.begin(); i != textures.end(); i++) {
		CleanUP(i->second);
	}
	textures.clear();
}