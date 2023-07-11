#include "Algorithm/Map.hpp"
#include <time.h>

Map::Map()
{
    _height = 10;
    _width = 10;
    _iteration = 0;
    _noisePercentage = 50;
}

Map::~Map()
{

}

void Map::createNoiseGrid()
{
    srand(time(0));
    for (int y = 0; y < _height; y++) {
        std::vector<int> temp;
        for (int x = 0; x < _width; x++) {
            int randomNb = rand() % 100;
            if (randomNb > _noisePercentage)
                temp.push_back(0);
            else
                temp.push_back(1);
        }
        _map.push_back(temp);
    }
}

void Map::displayMap()
{
    for (auto y = _map.begin(); y != _map.end(); y++) {
        for (auto x = (*y).begin(); x != (*y).end(); x++) {
            std::cout << *x << " ";
        }
        std::cout << std::endl;
    }
}