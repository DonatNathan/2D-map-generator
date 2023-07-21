#include <iostream>
#include <SDL2/SDL.h>

class Cell {
    public:
        Cell(int size, int x, int y, int color, bool isAdmin);
        ~Cell();

        void displayCell(SDL_Renderer *renderer);

    private:
        SDL_Rect _object;
        SDL_Color _color;
};
