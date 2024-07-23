//
// Created by lrfri on 22.07.2024.
//

#ifndef RAYLIBSTARTER_SWORD_H
#define RAYLIBSTARTER_SWORD_H

#include "ItemBase.h"

class sword : public ItemBase {
public:
    sword(float weight, const std::string& name, const std::string& description, int price, int strength);
};


#endif //RAYLIBSTARTER_SWORD_H
