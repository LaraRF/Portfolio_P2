//
// Created by lrfri on 23.07.2024.
//

#include "NPC.h"

NPC::NPC(int x, int y) : Character(x, y) {}

bool NPC::move(int dx, int dy) {
    m_x += dx;
    m_y += dy;
    return true;
}