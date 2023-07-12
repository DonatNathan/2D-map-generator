#include <iostream>
#include "Render/Window.hpp"

int main(int argc, char **argv)
{
    std::cout << "Hello Generator !" << std::endl;

    int height;
    int width;

    if (argc != 3 && argc != 1) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return 84;
    } else if (argc == 1) {
        height = 50;
        width = 50;
    } else {
        height = atoi(argv[2]);
        width = atoi(argv[1]);
    }

    Map theMap(width, height);
    theMap.createNoiseGrid();
    theMap.displayMap();

    Grid grid(&theMap);

    MyWindow win(&theMap, &grid);
    win.startLoop();

    return 0;
}