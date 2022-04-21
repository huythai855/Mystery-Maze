#include "header/SDL_Utils.h"
#include "header/texture.h"
#include "header/SDL_Libs.h"
#include "header/dot.h"
#include <iostream>

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

bool loadMedia(Texture &texture, std::string tmp){
	bool success = true;

	if( !texture.loadFromFile(tmp, renderer)){
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

int main(int argc, char* argv[]){


    Texture hp[4];
    int direction = 2;

    /// 1 up
    /// 2 right
    /// 3 down
    /// 4 left

    //loadMedia(hp[0], "img_src/right.png");

    bool ok = true;


    if(!init(window, renderer))
        std::cerr << "Failed to initialize!\n";
    else{
        if(!loadMedia(hp[0], "img_src/up.png") ||
           !loadMedia(hp[1], "img_src/right.png") ||
           !loadMedia(hp[2], "img_src/down.png") ||
           !loadMedia(hp[3], "img_src/left.png"))
            std::cerr << "Failed to load the media!\n";
        else{

            SDL_Rect gSpriteClips[4];
            gSpriteClips[ 0 ].x =   0;
            gSpriteClips[ 0 ].y =   0;
            gSpriteClips[ 0 ].w =  32;
            gSpriteClips[ 0 ].h = 48;

            gSpriteClips[ 1 ].x =  32;
            gSpriteClips[ 1 ].y =   0;
            gSpriteClips[ 1 ].w =  32;
            gSpriteClips[ 1 ].h = 48;

            gSpriteClips[ 2 ].x = 64;
            gSpriteClips[ 2 ].y =   0;
            gSpriteClips[ 2 ].w =  32;
            gSpriteClips[ 2 ].h = 48;

            gSpriteClips[ 3 ].x = 96;
            gSpriteClips[ 3 ].y =   0;
            gSpriteClips[ 3 ].w =  32;
            gSpriteClips[ 3 ].h = 48;
            int frame = 0;

            bool quit = false;
            SDL_Event event;
            Dot dot;

            while(!quit){
                while(SDL_PollEvent(&event) != 0){
                    if(event.type == SDL_QUIT)
                        quit = true;
                    dot.handleEvent(event, direction);
                }
                std::cerr << frame <<"\n";

                dot.move(frame);

                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];

                dot.render2(hp[direction], currentClip, renderer);
                SDL_RenderPresent(renderer);


            }

        }
    }

    // Free resources and close SDL
    close(window, renderer);
    //close1();




    return 0;
}
