#include "Algorithm/Map.hpp"
#include <time.h>

Map::Map(int width, int height)
{
    _height = height;
    _width = width;
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

std::vector<std::vector<int>> *Map::getMap()
{
    return &_map;
}

void Map::nextIteration()
{
    std::vector<std::vector<int>> newMap;

    for (auto y = _map.begin(); y != _map.end(); y++) {
        std::vector<int> temp;
        for (auto x = (*y).begin(); x != (*y).end(); x++) {
            int nbWalls = 0; //CountWall function
            if (nbWalls > 4)
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        newMap.push_back(temp);
    }
    _map = newMap;
}

void Map::increaseNoise()
{
    if (_noisePercentage <= 90) {
        _noisePercentage += 10;
        resetMap();
    } else {
        std::cout << "Can not increase noise percentage" << std::endl;
    }
}

void Map::decreaseNoise()
{
    if (_noisePercentage >= 10) {
        _noisePercentage -= 10;
        resetMap();
    } else {
        std::cout << "Can not decrease noise percentage" << std::endl;
    }
}

void Map::freeMap()
{
    _map.clear();
}

void Map::resetMap()
{
    freeMap();
    createNoiseGrid();
}