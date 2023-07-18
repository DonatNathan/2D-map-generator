#include "Render/Message.hpp"

Message::Message(std::string msg, SDL_Renderer *renderer)
{
    _font = TTF_OpenFont("assets/arial.ttf", 24);
    if (_font == NULL)
        std::cout << "Failed to load font : " << TTF_GetError() << std::endl;
    _color = {155, 155, 155};
    _text = TTF_RenderText_Solid(_font, msg.c_str(), {255, 255, 255, 255});
    _object = {0, 0, _text->w, _text->h};
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