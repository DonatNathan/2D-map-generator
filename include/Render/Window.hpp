#include <iostream>
#include <SDL2/SDL.h>
#include "Render/Grid.hpp"
#include "Render/Message.hpp"

class MyWindow {
    public:
        MyWindow(Map *map, Grid *grid);
        ~MyWindow();

        void startLoop();
        void checkEvents();
        void drawWindow();

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        bool _running;
        Map *_map;
        Grid *_grid;

        Message *_noiseMessage;
        Message *_iterationMessage;
        Message *_widthMessage;
        Message *_heightMessage;
};
