#include <iostream>
#include "header/SDL_Libs.h"
#include "header/globalVariables.h"

bool init(SDL_Window* &window, SDL_Renderer* &renderer){
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL couldn't initialize! SDL_Error: \n"
            << SDL_GetError();
        success = false;
    }
    else{
        window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        int imgFlags = IMG_INIT_PNG;
        IMG_Init(IMG_INIT_PNG);
    }
    return success;
};

void close(SDL_Window* &window, SDL_Renderer* &renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    SDL_Quit();
};

void waitUntilKeyPressed(){
    SDL_Event event;
    while(true){
        if(SDL_WaitEvent(&event)!=0 && event.type == SDL_KEYDOWN)
            return;
        SDL_Delay(500);
    }
};




