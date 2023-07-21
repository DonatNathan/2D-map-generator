#include <iostream>
#include <fstream>
#include <vector>

class Map {
    public:
        Map(int width, int height);
        ~Map();

        std::vector<int> getVector(int i);
        int getCell(std::vector<int>& vector, int i);

        void createNoiseGrid();
        void displayMap();
        void nextIteration();
        void previousIteration();
        void increaseNoise();
        void decreaseNoise();
        void freeMap();
        void resetMap();

        int countWall(int x, int y);
        void checkTwoSides(std::vector<int>& vector, int x, int *nbWalls, bool mid);

        void writeMapOnFile(std::string path);

        std::vector<std::vector<int>> *getMap();
        int getNoise();
        int getIteration();
        int getWidth();
        int getHeight();

    private:
        std::vector<std::vector<int>> _map;
        int _noisePercentage;
        int _iteration;
        int _height;
        int _width;
};
