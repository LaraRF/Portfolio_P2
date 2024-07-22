//
// Created by lrfri on 09.07.2024.
//

#ifndef RAYLIBSTARTER_MAP_H
#define RAYLIBSTARTER_MAP_H


#include <vector>
#include "raylib.h"
#include "config.h"
#include <random>
#include <queue>

enum TileType {Traversable, Blocked, Beginning, End, TreasureChest};

struct Node {
    int x, y;
    int g, h;
    int f() const { return g + h; }
    Node* parent;

    Node(int x, int y) : x(x), y(y), g(0), h(0), parent(nullptr) {}
};

struct CompareNode {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->f() > rhs->f();
    }
};

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

private:
    std::vector<std::vector<TileType>> Map;
    std::mt19937 randomnumbergenerator;

    void initializeMap();
    void placeStartAndEnd();
    void addObstacles();
    bool isValidMove(int x, int y) const;
    bool findPathAStar();
    int calculateHeuristic(int x1, int y1, int x2, int y2) const;
};


#endif //RAYLIBSTARTER_MAP_H
