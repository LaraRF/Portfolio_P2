//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_RING_H
#define RAYLIBSTARTER_RING_H
#include "ItemBase.h"

class ring:public ItemBase {
public:
    ring(float weight, const std::string& name, const std::string& description, int price, int strength);
};


#endif //RAYLIBSTARTER_RING_H
