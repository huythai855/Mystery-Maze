#include "header/SDL_Utils.h"
#include "header/texture.h"
#include "header/SDL_Libs.h"
#include "header/dot.h"
#include <iostream>

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

bool loadMedia(Texture &texture){
	bool success = true;

    std::string tmp = "img_src/character.png";
	if( !texture.loadFromFile(tmp, renderer))
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

int main(int argc, char* argv[]){


    Texture texture;

    //SDL_Texture


    if(!init(window, renderer))
        std::cerr << "Failed to initialize!\n";
    else{
        if(!loadMedia(texture))
            std::cerr << "Failed to load the media!\n";
        else{

            bool quit = false;
            SDL_Event event;
            Dot dot;

            std::cerr << "oke em\n";
            while(!quit){
                while(SDL_PollEvent(&event) != 0){
                    if(event.type == SDL_QUIT)
                        quit = true;
                    dot.handleEvent(event);
                }

                dot.move();
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                dot.render(texture, renderer);
                SDL_RenderPresent(renderer);
            }

        }
    }

    close(window, renderer);



    return 0;
}
