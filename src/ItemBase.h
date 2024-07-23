//
// Created by lrfri on 22.07.2024.
//

#ifndef RAYLIBSTARTER_ITEMBASE_H
#define RAYLIBSTARTER_ITEMBASE_H

#include <string>
#include "raylib.h"

class ItemBase {

protected:
    float weight =1;
    float price=0;
    std::string name;
    std::string description;

public:
    //Position on Map
    int x;
    int y;

    ItemBase(const std::string& name, float weight, const std::string& description, int price)
            : name(name), weight(weight), description(description), price(price), x(-1), y(-1) {}

    virtual ~ItemBase() = default;

    // Getters
    std::string getName() const { return name; }
    float getWeight() const { return weight; }
    std::string getDescription() const { return description; }
    int getPrice() const { return price; }
};


#endif //RAYLIBSTARTER_ITEMBASE_H
