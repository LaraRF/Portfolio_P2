//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_NPC_H
#define RAYLIBSTARTER_NPC_H

#include "Character.h"

class NPC : public Character {
public:
    NPC(int x, int y);
    bool move(int dx, int dy) override;
};

#endif //RAYLIBSTARTER_NPC_H
