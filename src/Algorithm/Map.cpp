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

    int cmpt_y = 1;
    for (auto y = _map.begin(); y != _map.end(); y++, cmpt_y++) {
        std::vector<int> temp;
        int cmpt_x = 1;
        for (auto x = (*y).begin(); x != (*y).end(); x++, cmpt_x++) {
            int nbWalls = countWall(cmpt_x, cmpt_y); //CountWall function
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

int Map::countWall(int x, int y)
{
    int nbWalls = 0;
    int nbBorders = 0;

    if (y == 1) {
        nbWalls += 3;
        nbBorders++;
    } else {
        std::vector<int> vec = getVector(y - 1);
        checkTwoSides(vec, x, &nbWalls, false);
    }

    std::vector<int> midVec = getVector(y);
    checkTwoSides(midVec, x, &nbWalls, true);

    if (y == (int)_map.size()) {
        nbWalls += 3;
        nbBorders++;
    } else {
        std::vector<int> vec = getVector(y + 1);
        checkTwoSides(vec, x, &nbWalls, false);
    }

    if (x == 1) {
        nbWalls += 3;
        nbBorders++;
    }
    if (x == (int)(*_map.begin()).size()) {
        nbWalls += 3;
        nbBorders++;
    }
    if (nbBorders == 4)
        nbWalls -= nbBorders;
    else if (nbBorders > 1)
        nbWalls -= nbBorders - 1;
    return nbWalls;
}

void Map::checkTwoSides(std::vector<int> vector, int x, int *nbWalls, bool mid)
{
    if (x != 1)
        *nbWalls += getCell(vector, x - 1);
    if (!mid)
        *nbWalls += getCell(vector, x);
    if (x != (int)(*_map.begin()).size())
        *nbWalls += getCell(vector, x + 1);
}

std::vector<int> Map::getVector(int i)
{
    int cmpt = 1;
    auto vector = _map.begin();
    for (; cmpt != i; vector++, cmpt++);
    return *vector;
}

int Map::getCell(std::vector<int> vector, int i)
{
    int cmpt = 1;
    auto cell = vector.begin();
    for (; cmpt != i; cell++, cmpt++);
    return *cell;
}