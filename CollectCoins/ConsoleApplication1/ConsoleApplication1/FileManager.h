#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <iterator>
#include <string>

class Application;

class FileManager {
private:
	std::map <std::string, SDL_Texture*> textures;
	Application* game;

public:
	FileManager(Application* game);
	~FileManager();

	SDL_Texture* GetTexture(std::string filename);
};

#endif
