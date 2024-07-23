//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_CHARACTER_H
#define RAYLIBSTARTER_CHARACTER_H

#include <utility>

class Character {

public:
    Character(int x, int y);
    virtual ~Character() = default;

    virtual bool move(int dx, int dy) = 0;
    std::pair<int, int> getPosition() const;

protected:
    int m_x, m_y;

};


#endif //RAYLIBSTARTER_CHARACTER_H
