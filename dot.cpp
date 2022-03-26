#include "header/dot.h"
#include "header/globalVariables.h"
#include <iostream>

Dot::Dot(){
    PosX = PosY = 0;
    VelX = VelY = 0;
    Vel = DOT_VEL;
};

void Dot::handleEvent(SDL_Event &e){
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
        switch( e.key.keysym.sym ){
            case SDLK_UP: VelY -= DOT_VEL; std::cout << "up"<< VelY <<"\n"; break;
            case SDLK_DOWN: VelY += DOT_VEL; std::cout << "down"<< VelY <<"\n"; break;
            case SDLK_LEFT: VelX -= DOT_VEL; std::cout << "left"<< VelX <<"\n"; break;
            case SDLK_RIGHT: VelX += DOT_VEL; std::cout << "right"<< VelX <<"\n";break;

        }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0)
        switch( e.key.keysym.sym ){
            case SDLK_UP: VelY += DOT_VEL; break;
            case SDLK_DOWN: VelY -= DOT_VEL; break;
            case SDLK_LEFT: VelX += DOT_VEL; break;
            case SDLK_RIGHT: VelX -= DOT_VEL; break;
        }
}

void Dot::move(){
    PosX += VelX;
    PosY += VelY;
    if( ( PosX < 0 ) || ( PosX + DOT_WIDTH > SCREEN_WIDTH ) )
        PosX -= VelX;
    if( ( PosY < 0 ) || ( PosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
        PosY -= VelY;
}

void Dot::render(Texture &texture, SDL_Renderer* &renderer){
    texture.render(PosX, PosY, renderer);
}

