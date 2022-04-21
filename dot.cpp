#include "header/dot.h"
#include "header/globalVariables.h"
#include <iostream>

Dot::Dot(){
    PosX = PosY = 0;
    VelX = VelY = 0;
    Vel = DOT_VEL;
};

void Dot::handleEvent(SDL_Event &e, int &direction){
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
        switch( e.key.keysym.sym ){
            case SDLK_UP:
                VelY -= DOT_VEL;
                direction = 0;
                break;
            case SDLK_RIGHT:
                VelX += DOT_VEL;
                direction = 1;
                break;
            case SDLK_DOWN:
                VelY += DOT_VEL;
                direction = 2;
                break;
            case SDLK_LEFT:
                VelX -= DOT_VEL;
                direction = 3;
                break;
        }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0)
        switch( e.key.keysym.sym ){
            case SDLK_UP: VelY += DOT_VEL; break;
            case SDLK_DOWN: VelY -= DOT_VEL; break;
            case SDLK_LEFT: VelX += DOT_VEL; break;
            case SDLK_RIGHT: VelX -= DOT_VEL; break;
        }
}

void Dot::move(int &frame){
    PosX += VelX;
    PosY += VelY;

    if(VelX != 0 || VelY != 0){
        ++frame;
        if(frame / DECREASE_FOOT_STEP >= NUMBER_OF_SPRITE)
            frame = 0;
    }

    if( ( PosX < 0 ) || ( PosX + CHARACTER_WIDTH > SCREEN_WIDTH ) )
        PosX -= VelX;
    if( ( PosY < 0 ) || ( PosY + CHARACTER_HEIGHT > SCREEN_HEIGHT ) )
        PosY -= VelY;
}

void Dot::render(Texture &texture, SDL_Renderer* &renderer){
    texture.render(PosX, PosY, renderer);
}

void Dot::render2(Texture &texture, SDL_Rect* clip, SDL_Renderer* &renderer){
    SDL_Rect renderQuad = { PosX, PosY, CHARACTER_WIDTH, CHARACTER_HEIGHT};
    if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
    SDL_RenderCopy( renderer, texture.texture, clip, &renderQuad);
}

