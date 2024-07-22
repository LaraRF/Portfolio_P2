//
// Created by lrfri on 09.07.2024.
//

#ifndef RAYLIBSTARTER_MAP_H
#define RAYLIBSTARTER_MAP_H


#include <vector>
#include "raylib.h"
#include "config.h"
#include <random>

class map {
protected:
    int mapWidth{};
    int mapHeight{};
    std::vector<int> tileMap;
public:
    map();
    void generateMap();
    void drawMap(int screenWidth, int screenHeight);

    const int mapsize=15;
    const int tilesize=32;

    enum TileType {Traversable, Blocked, Beginning, End};
private:
    std::vector<std::vector<TileType>> Map;
    std::mt19937 randomnumbergenerator;

    void initializeMap();
    void placeStartAndEnd();
    void addObstacles();
    bool isValidMove(int x, int y);
    bool findPath();
};


#endif //RAYLIBSTARTER_MAP_H
