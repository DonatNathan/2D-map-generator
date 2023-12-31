#include "Render/Grid.hpp"

Grid::Grid(Map *map)
{
    _map = map;
    int sizeX = 1880 / _map->getWidth();
    int sizeY = 1000 / _map->getHeight();
    _size = (sizeX > sizeY ? sizeY : sizeX);
    createGrid();
}

Grid::~Grid()
{

}

void Grid::setIsAdmin(bool *isAdmin)
{
    _isAdmin = isAdmin;
}

void Grid::createGrid()
{
    int cmpt_y = 0;
    for (auto y = _map->getMap()->begin(); y != _map->getMap()->end(); y++, cmpt_y++) {
        std::vector<Cell *> temp;
        int cmpt_x = 0;
        for (auto x = (*y).begin(); x != (*y).end(); x++, cmpt_x++) {
            temp.push_back(new Cell(_size, cmpt_x * (_size + 1), cmpt_y * (_size + 1), (*x), *_isAdmin));
        }
        _grid.push_back(temp);
    }
}

void Grid::displayGrid(SDL_Renderer *renderer)
{
    for (auto y = _grid.begin(); y != _grid.end(); y++) {
        for (auto x = (*y).begin(); x != (*y).end(); x++) {
            (*x)->displayCell(renderer);
        }
    }
}

void Grid::freeGrid()
{
    _grid.clear();
}

void Grid::resetGrid()
{
    freeGrid();
    createGrid();
}
