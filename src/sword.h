//
// Created by lrfri on 22.07.2024.
//

#ifndef RAYLIBSTARTER_SWORD_H
#define RAYLIBSTARTER_SWORD_H

#include "ItemBase.h"

class sword : public ItemBase {

public:
    sword(const std::string& name, float weight, const std::string& description, int price)
            : ItemBase(name, weight, description, price) {}

};


#endif //RAYLIBSTARTER_SWORD_H
