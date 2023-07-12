#include "Render/Window.hpp"

MyWindow::MyWindow(Map *map, Grid *grid)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "Failed to open SDL video library" << std::endl;
    _window = SDL_CreateWindow("Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    if (!_window)
        std::cerr << "Failed to load window" << std::endl;
    _surface = SDL_GetWindowSurface(_window);
    if (!_surface)
        std::cerr << "Failed to load surface" << std::endl;
    _map = map;
    _grid = grid;
}

MyWindow::~MyWindow()
{
    SDL_FreeSurface(_surface);
    SDL_DestroyWindow(_window);
}

void MyWindow::drawWindow()
{
    SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0, 0, 0));
    _grid->displayGrid(_surface);
    SDL_UpdateWindowSurface(_window);
}

void MyWindow::startLoop()
{
    while (_running) {
        checkEvents();
        drawWindow();
    }
}

void MyWindow::checkEvents()
{
    while (SDL_PollEvent(&_event) > 0) {
        if (_event.type == SDL_QUIT)
            _running = false;
    }
}