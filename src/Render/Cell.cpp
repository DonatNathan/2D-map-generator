#include "Render/Cell.hpp"

Cell::Cell(int size, int x, int y, int color)
{
    _object = {x, y, size, size};
    if (color == 0)
        _color = {255, 255, 255};
    else
        _color = {0, 0, 0};
}

Cell::~Cell()
{

}

void Cell::displayCell(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, 255);
    SDL_RenderFillRect(renderer, &_object);
}
