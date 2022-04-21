#include <iostream>
#include "header/SDL_Libs.h"
#include "header/texture.h"

Texture :: Texture(){
    texture = NULL;
    Width = 0;
    Height = 0;
}

void Texture :: free(){
    if(texture != NULL){
        SDL_DestroyTexture(texture);
        texture = NULL;
        Width = 0;
        Height = 0;
    }
}

bool Texture :: loadFromFile(std::string &path, SDL_Renderer* &renderer){
    free();
    texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    Width = loadedSurface -> w;
    Height = loadedSurface -> h;

    SDL_FreeSurface(loadedSurface);
    return (texture != NULL);
}

void Texture :: render(int x, int y, SDL_Renderer* &renderer){
    SDL_Rect characterRect;
    SDL_QueryTexture(texture, NULL, NULL, &characterRect.w, &characterRect.h);

    characterRect.x = x;
    characterRect.y = y;
    SDL_RenderCopy(renderer, texture, NULL, &characterRect);
}

//void Texture :: render2( int x, int y, SDL_Rect* clip, SDL_Renderer* &renderer)
//{
//	//Set rendering space and render to screen
//	SDL_Rect renderQuad = { x, y, 32, 48 };
//
//	//Set clip rendering dimensions
//	if( clip != NULL ){
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//
//	//Render to screen
//	SDL_RenderCopy( renderer, texture, clip, &renderQuad);
//
//}
