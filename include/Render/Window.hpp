#include <iostream>
#include <memory>
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
        void drawInfos();

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        bool _running;
        Map *_map;
        Grid *_grid;

        std::unique_ptr<Message> _noiseMessage;
        std::unique_ptr<Message> _iterationMessage;
        std::unique_ptr<Message> _widthMessage;
        std::unique_ptr<Message> _heightMessage;

        bool _displayInfos;
        bool _adminMod;
};
