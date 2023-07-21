#include "Render/Window.hpp"

MyWindow::MyWindow(Map *map, Grid *grid)
{
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "Failed to open SDL video library : " << SDL_GetError() << std::endl;
    _window = SDL_CreateWindow("Generator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    if (!_window)
        std::cerr << "Failed to load window : " << SDL_GetError() << std::endl;
    _map = map;
    _grid = grid;
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if (!_renderer)
        std::cerr << "Failed to load renderer : " << SDL_GetError() << std::endl;
    _running = true;
    _noiseMessage = new Message("Noise percentage : ", _renderer, 0, 0, _map->getNoise());
    _iterationMessage = new Message("Iteration : ", _renderer, 0, 25, _map->getIteration());
    _heightMessage = new Message("Height : ", _renderer, 0, 50, _map->getHeight());
    _widthMessage = new Message("Width : ", _renderer, 0, 75, _map->getWidth());
}

MyWindow::~MyWindow()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

void MyWindow::drawWindow()
{
    SDL_SetRenderDrawColor(_renderer, 155, 155, 155, 255);
    SDL_RenderClear(_renderer);
    _grid->displayGrid(_renderer);
    _noiseMessage->displayMessage(_renderer);
    _iterationMessage->displayMessage(_renderer);
    _heightMessage->displayMessage(_renderer);
    _widthMessage->displayMessage(_renderer);
    SDL_RenderPresent(_renderer);
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
        if (_event.type == SDL_KEYDOWN) {
            if (_event.key.keysym.sym == SDLK_RIGHT) {
                _map->nextIteration();
                _grid->resetGrid();
                _iterationMessage->updateMessage(_renderer, _map->getIteration());
            }
            if (_event.key.keysym.sym == SDLK_UP) {
                _map->increaseNoise();
                _grid->resetGrid();
                _noiseMessage->updateMessage(_renderer, _map->getNoise());
                _iterationMessage->updateMessage(_renderer, _map->getIteration());
            }
            if (_event.key.keysym.sym == SDLK_DOWN) {
                _map->decreaseNoise();
                _grid->resetGrid();
                _noiseMessage->updateMessage(_renderer, _map->getNoise());
                _iterationMessage->updateMessage(_renderer, _map->getIteration());
            }
            if (_event.key.keysym.sym == SDLK_RETURN)
                _map->writeMapOnFile();
        }
    }
}
