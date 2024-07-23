//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_SHIELD_H
#define RAYLIBSTARTER_SHIELD_H

#include "ItemBase.h"

class Shield : public ItemBase {
public:
    Shield(float weight, const std::string& name, const std::string& description, int price, int addedstrength);
};


#endif //RAYLIBSTARTER_SHIELD_H
