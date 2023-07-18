#include "Render/Message.hpp"

Message::Message(std::string msg, SDL_Renderer *renderer)
{
    TTF_Init();
    _font = TTF_OpenFont("assets/arial.ttf", 24);
    if (_font == NULL)
        std::cout << "Failed to load font : " << TTF_GetError() << std::endl;
    _color = {255, 0, 0};
    _text = TTF_RenderText_Solid(_font, msg.c_str(), _color);
    _object = {0, 0, 100, 100};
    _texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 1024, 1024);
}

Message::~Message()
{

}

void Message::displayMessage(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, _texture, _object);
    SDL_RenderFillRect(renderer, &_object);
}