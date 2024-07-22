//
// Created by lrfri on 09.07.2024.
//

#include <queue>
#include "map.h"

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

bool map::isValidMove(int x, int y) {
    return x >= 0 && x < mapsize && y >= 0 && y < mapsize && Map[y][x] != TileType::Blocked;
}

bool map::findPath() {
    std::vector<std::vector<bool>> visited(mapsize, std::vector<bool>(mapsize, false));
    std::queue<std::pair<int, int>> q;

    // Find start position
    int startX, startY;
    for (int i = 0; i < mapsize; ++i) {
        if (Map[mapsize - 1][i] == TileType::Beginning) {
            startX = i;
            startY = mapsize - 1;
            break;
        }
    }
    q.push({startX, startY});
    visited[startY][startX] = true;

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (Map[y][x] == TileType::End) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValidMove(newX, newY) && !visited[newY][newX]) {
                visited[newY][newX] = true;
                q.push({newX, newY});
            }
        }
    }

    return false;
}

void map::generateMap() {
    do {
        initializeMap();
        placeStartAndEnd();
        addObstacles();
    } while (!findPath());
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