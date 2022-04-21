#include "header/SDL_Utils.h"
#include "header/texture.h"
#include "header/SDL_Libs.h"
#include "header/dot.h"
#include "header/globalVariables.h"
#include <iostream>

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;
Texture character[NUMBER_OF_SPRITE];
SDL_Rect spriteClips[4];
int character_choice = 0;

int direction = DOWN;


bool loadMedia(Texture &texture, std::string tmp){
	bool success = true;
	if( !texture.loadFromFile(tmp, renderer)){
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
	return success;
}

void initDirection(){
    for(int i=0; i<=3; i++){
        spriteClips[i].x = i * CHARACTER_WIDTH;
        spriteClips[i].y = 0;
        spriteClips[i].w = CHARACTER_WIDTH;
        spriteClips[i].h = CHARACTER_HEIGHT;
    }
}

bool loadCharacter(){
    std::string c_up = "img_src/" + pre[character_choice] + "_up.png";
    std::string c_right = "img_src/" + pre[character_choice] + "_right.png";
    std::string c_down = "img_src/" + pre[character_choice] + "_down.png";
    std::string c_left = "img_src/" + pre[character_choice] + "_left.png";

    if(!loadMedia(character[UP], c_up) ||
       !loadMedia(character[RIGHT], c_right) ||
       !loadMedia(character[DOWN], c_down) ||
       !loadMedia(character[LEFT], c_left))
        return false;
    return true;
}

int main(int argc, char* argv[]){

    if(!init(window, renderer))
        std::cerr << "Failed to initialize!\n";
    else{
        if(!loadCharacter())
            std::cerr << "Failed to load character!\n";
        else{
            initDirection();
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

                dot.move(frame);

                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(renderer);

                SDL_Rect* currentClip = &spriteClips[ frame / DECREASE_FOOT_STEP];

                dot.render2(character[direction], currentClip, renderer);
                SDL_RenderPresent(renderer);
            }
        }
    }

    close(window, renderer);


    return 0;
}
