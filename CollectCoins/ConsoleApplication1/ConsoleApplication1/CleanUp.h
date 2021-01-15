#ifndef CLEANUP_H
#define CLEANUP_H

//This feature was made by TwinkleBearDev for his tutorials, so credits to him

#include <SDL.h>

template<typename T, typename... Args>
void CleanUP(T *t, Args&&... args) {
	CleanUP(t);

	CleanUP(std::forward<Args>(args)...);
}

template<>
inline void CleanUP<SDL_Window>(SDL_Window* window) {
	if (!window)
		return;

	SDL_DestroyWindow(window);
}

template<>
inline void CleanUP<SDL_Renderer>(SDL_Renderer* render) {
	if (!render)
		return;

	SDL_DestroyRenderer(render);
}

template<>
inline void CleanUP<SDL_Texture>(SDL_Texture* texture) {
	if (!texture)
		return;

	SDL_DestroyTexture(texture);
}

#endif