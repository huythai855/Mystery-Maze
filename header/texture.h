#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include<string.h>
#include<string>

class Texture{
    private:
        SDL_Texture* texture;
        int Width;
        int Height;
    public:
        Texture();
        void free();
        bool loadFromFile(std::string &path, SDL_Renderer* &renderer);
        void render(int x, int y, SDL_Renderer* &renderer);
};


#endif // TEXTURE_H_INCLUDED
