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

void Cell::displayCell(SDL_Surface *surface)
{
    SDL_FillRect(surface, &_object, SDL_MapRGB(surface->format, _color.r, _color.g, _color.b));
}