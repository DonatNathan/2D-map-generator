#include <iostream>
#include <vector>

class Map {
    public:
        Map(int width, int height);
        ~Map();

        void createNoiseGrid();
        void displayMap();
        std::vector<std::vector<int>> *getMap();

    private:
        std::vector<std::vector<int>> _map;
        int _noisePercentage;
        int _iteration;
        int _height;
        int _width;
};
