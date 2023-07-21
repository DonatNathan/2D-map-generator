#include "Render/Message.hpp"

Message::Message(std::string msg, SDL_Renderer *renderer, int x, int y, int value)
{
    _base = msg;
    _posX = x;
    _posY = y;
    _font = TTF_OpenFont("assets/arial.ttf", 24);
    if (_font == NULL)
        std::cout << "Failed to load font : " << TTF_GetError() << std::endl;
    _color = {100, 100, 100};
    _text = TTF_RenderText_Solid(_font, (_base + std::to_string(value)).c_str(), {255, 255, 255, 255});
    _object = {_posX, _posY, _text->w, _text->h};
    _texture = SDL_CreateTextureFromSurface(renderer, _text);
}

Message::~Message()
{

}

void Message::displayMessage(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, 255);
    SDL_RenderFillRect(renderer, &_object);
    SDL_RenderCopy(renderer, _texture, NULL, &_object);
}

void Message::updateMessage(SDL_Renderer *renderer, int value)
{
    _text = TTF_RenderText_Solid(_font, (_base + std::to_string(value)).c_str(), {255, 255, 255, 255});
    _object = {_posX, _posY, _text->w, _text->h};
    _texture = SDL_CreateTextureFromSurface(renderer, _text);
}