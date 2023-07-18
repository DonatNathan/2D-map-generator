#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>

class Message {
    public:
        Message(std::string msg, SDL_Renderer *renderer);
        ~Message();

        void displayMessage(SDL_Renderer *renderer);

    private:
        TTF_Font *_font;
        SDL_Color _color;
        SDL_Surface *_text;
        SDL_Rect _object;
        SDL_Texture *_texture;
};
