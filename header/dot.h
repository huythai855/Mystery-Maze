#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include "SDL_Libs.h"
#include "texture.h"

class Dot{
    public:
        const int DOT_WIDTH = 20;
        const int DOT_HEIGHT = 20;

        Dot();
        void handleEvent(SDL_Event &e);
        void move();
        void render(Texture &texture, SDL_Renderer* &renderer);

    private:
        int PosX, PosY;
        int VelX, VelY;
        int Vel;
};


#endif // DOT_H_INCLUDED