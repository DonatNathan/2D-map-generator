#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Render/Cell.hpp"
#include "Algorithm/Map.hpp"

class Grid {
    public:
        Grid(Map *map);
        ~Grid();

        void createGrid();
        void displayGrid(SDL_Surface *surface);
        void resetGrid();
        void freeGrid();
    private:
        std::vector<std::vector<Cell *>> _grid;
        Map *_map;
        int _size;
};
