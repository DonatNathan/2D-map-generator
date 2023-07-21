#include "Render/Cell.hpp"

Cell::Cell(int size, int x, int y, int color, bool isAdmin)
{
    _object = {x, y, size, size};
    if (isAdmin) {
        if (color == 0)
            _color = {255, 255, 255};
        else
            _color = {0, 0, 0};
    } else {
        if (color == 0)
            _color = {0, 255, 0};
        else
            _color = {0, 0, 255};
    }
}

Cell::~Cell()
{

}

void Cell::displayCell(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, 255);
    SDL_RenderFillRect(renderer, &_object);
}
