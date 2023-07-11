#include <iostream>
#include "Algorithm/Map.hpp"
#include "Render/Window.hpp"

int main(int argc, char **argv)
{
    std::cout << "Hello Generator !" << std::endl;

    Map theMap;
    theMap.createNoiseGrid();
    theMap.displayMap();

    MyWindow win;
    win.startLoop();

    return 0;
}