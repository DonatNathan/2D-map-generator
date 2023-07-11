#include <iostream>
#include <SDL2/SDL.h>

class MyWindow {
    public:
        MyWindow();
        ~MyWindow();

        void startLoop();
        void checkEvents();
        void drawWindow();

    private:
        SDL_Window *_window;
        SDL_Event _event;
        SDL_Surface *_surface;
        bool _running;
};
