//
// Created by lrfri on 22.07.2024.
//

#ifndef RAYLIBSTARTER_ITEMBASE_H
#define RAYLIBSTARTER_ITEMBASE_H

#include <string>
#include "raylib.h"

class ItemBase {

public:
    ItemBase(float weight, const std::string& name, const std::string& description, int price, int strength);
    virtual ~ItemBase() = default;

    float getWeight() const;
    const std::string& getName() const;
    const std::string& getDescription() const;
    int getPrice() const;
    int getStrength() const;

    int x;
    int y;

private:
    float m_weight;
    std::string m_name;
    std::string m_description;
    int m_price;
    int m_strength;
};


#endif //RAYLIBSTARTER_ITEMBASE_H
