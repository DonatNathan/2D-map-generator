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
        void displayGrid(SDL_Renderer *renderer);
        void resetGrid();
        void freeGrid();
        void setIsAdmin(bool *isAdmin);

    private:
        std::vector<std::vector<Cell *>> _grid;
        Map *_map;
        int _size;
        bool *_isAdmin;
};
