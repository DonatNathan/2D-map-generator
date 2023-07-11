#include <iostream>
#include <vector>

class Map {
    public:
        Map();
        ~Map();

        void createNoiseGrid();
        void displayMap();

    private:
        std::vector<std::vector<int>> _map;
        int _noisePercentage;
        int _iteration;
        int _height;
        int _width;
};
