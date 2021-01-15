#ifndef ENTITIES_H
#define ENTITIES_H

#include "Application.h"
#include "FileManager.h"

class Entities {
protected:
	float x, y;
	float sizeX, sizeY;

	Application* game;
	FileManager* filemanager;

	SDL_Rect src_rect, dst_rect;

public:
	virtual void Init(Application* game, FileManager* filemanager) = 0;
	virtual void Update(float deltaTime, int camZoomX, int camZoomY) = 0;
	virtual void Render() = 0;

	bool CollidesWith(Entities* body);
};

#endif