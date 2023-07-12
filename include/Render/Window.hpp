#include <iostream>
#include <SDL2/SDL.h>
#include "Render/Grid.hpp"

class MyWindow {
    public:
        MyWindow(Map *map, Grid *grid);
        ~MyWindow();

        void startLoop();
        void checkEvents();
        void drawWindow();

    private:
        SDL_Window *_window;
        SDL_Event _event;
        SDL_Surface *_surface;
        bool _running;
        Map *_map;
        Grid *_grid;
};
