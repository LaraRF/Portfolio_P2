//
// Created by lrfri on 22.07.2024.
//

#ifndef RAYLIBSTARTER_SWORD_H
#define RAYLIBSTARTER_SWORD_H

#include "ItemBase.h"

class Sword : public ItemBase {
public:
    Sword(float weight, const std::string& name, const std::string& description, int price, int addedstrength);
};


#endif //RAYLIBSTARTER_SWORD_H
