#ifndef SDL_UTILS_H_INCLUDED
#define SDL_UTILS_H_INCLUDED

#include "SDL_Libs.h"

bool init(SDL_Window* &window, SDL_Renderer* &renderer);

void close(SDL_Window* &window, SDL_Renderer* &renderer);

void waitUntilKeyPressed();

#endif // SDL_UTILS_H_INCLUDED
