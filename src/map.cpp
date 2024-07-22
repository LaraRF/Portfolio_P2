//
// Created by lrfri on 09.07.2024.
//

#include "map.h"
#include <queue>
#include <algorithm>
#include <unordered_set>

map::map() : randomnumbergenerator(std::random_device{}()) {}

void map::initializeMap() {
    Map = std::vector<std::vector<TileType>>(mapsize, std::vector<TileType>(mapsize, TileType::Traversable));
}

void map::placeStartAndEnd() {
    int startX = std::uniform_int_distribution<>(0, mapsize - 1)(randomnumbergenerator);
    int endX = std::uniform_int_distribution<>(0, mapsize - 1)(randomnumbergenerator);
    Map[mapsize - 1][startX] = TileType::Beginning;
    Map[0][endX] = TileType::End;
}

void map::addObstacles() {
    for (int i = 0; i < mapsize; ++i) {
        for (int j = 0; j < mapsize; ++j) {
            if (Map[i][j] == TileType::Traversable && std::uniform_real_distribution<>()(randomnumbergenerator) < 0.3) {
                Map[i][j] = TileType::Blocked;
            }
        }
    }
}

bool map::isValidMove(int x, int y)const {
    return x >= 0 && x < mapsize && y >= 0 && y < mapsize && Map[y][x] != TileType::Blocked;
}

bool map::findPathAStar() {
    std::vector<std::vector<Node*>> nodes(mapsize, std::vector<Node*>(mapsize, nullptr));
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
    std::unordered_set<Node*> openSetHash;

    // Find start and end positions
    int startX, startY, endX, endY;
    for (int i = 0; i < mapsize; ++i) {
        if (Map[mapsize - 1][i] == TileType::Beginning) {
            startX = i;
            startY = mapsize - 1;
        }
        if (Map[0][i] == TileType::End) {
            endX = i;
            endY = 0;
        }
    }

    // Create start node and add to open set
    Node* startNode = new Node(startX, startY);
    startNode->h = calculateHeuristic(startX, startY, endX, endY);
    openSet.push(startNode);
    openSetHash.insert(startNode);
    nodes[startY][startX] = startNode;

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();
        openSetHash.erase(current);

        if (current->x == endX && current->y == endY) {
            // Path found, clean up and return true
            for (auto& row : nodes) {
                for (auto& node : row) {
                    delete node;
                }
            }
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if (isValidMove(newX, newY)) {
                int newG = current->g + 1;

                Node* neighbor = nodes[newY][newX];
                if (!neighbor) {
                    neighbor = new Node(newX, newY);
                    neighbor->h = calculateHeuristic(newX, newY, endX, endY);
                    nodes[newY][newX] = neighbor;
                }

                if (newG < neighbor->g || neighbor->g == 0) {
                    neighbor->parent = current;
                    neighbor->g = newG;
                    if (openSetHash.find(neighbor) == openSetHash.end()) {
                        openSet.push(neighbor);
                        openSetHash.insert(neighbor);
                    }
                }
            }
        }
    }

    // No path found, clean up and return false
    for (auto& row : nodes) {
        for (auto& node : row) {
            delete node;
        }
    }
    return false;
}

int map::calculateHeuristic(int x1, int y1, int x2, int y2) const {
    // Manhattan distance
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void map::generateMap() {
    do {
        initializeMap();
        placeStartAndEnd();
        addObstacles();
    } while (!findPathAStar());
}

void map::drawMap(int screenWidth, int screenHeight) {
    int mapWidth = mapsize * tilesize;
    int mapHeight = mapsize * tilesize;
    int offsetX = (screenWidth - mapWidth) / 2;
    int offsetY = (screenHeight - mapHeight) / 2;

    for (int y = 0; y < mapsize; ++y) {
        for (int x = 0; x < mapsize; ++x) {
            Rectangle tileRect = {
                    static_cast<float>(offsetX + x * tilesize),
                    static_cast<float>(offsetY + y * tilesize),
                    static_cast<float>(tilesize), static_cast<float>(tilesize)
            };

            switch (Map[y][x]) {
                case TileType::Traversable:
                    DrawRectangleRec(tileRect, DARKGREEN);
                    break;
                case TileType::Blocked:
                    DrawRectangleRec(tileRect, DARKGRAY);
                    break;
                case TileType::Beginning:
                    DrawRectangleRec(tileRect, BLUE);
                    break;
                case TileType::End:
                    DrawRectangleRec(tileRect, GOLD);
                    break;
            }
            //DrawRectangleLinesEx(tileRect, 1, BLACK); //macht Grid um die einzelnen Tiles
        }
    }
}