//
// Created by lrfri on 23.07.2024.
//

#include "Character.h"

Character::Character(int x, int y) : m_x(x), m_y(y) {}

std::pair<int, int> Character::getPosition() const {
    return {m_x, m_y};
}