#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>

class Message {
    public:
        Message(std::string msg, SDL_Renderer *renderer, int x, int y, int value);
        ~Message();

        void displayMessage(SDL_Renderer *renderer);
        void updateMessage(SDL_Renderer *renderer, int value);

    private:
        std::string _base;
        TTF_Font *_font;
        SDL_Color _color;
        SDL_Surface *_text;
        SDL_Rect _object;
        SDL_Texture *_texture;
        int _posX;
        int _posY;
};
