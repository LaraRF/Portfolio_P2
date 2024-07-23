//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_PLAYERCHAR_H
#define RAYLIBSTARTER_PLAYERCHAR_H

#include "Character.h"
#include "ItemBase.h"
#include "Inventory.h"

class PlayerChar : public Character {
public:
    PlayerChar(int x, int y, int strength);

    bool move(int dx, int dy) override;
    bool pickUpItem(ItemBase* item);
    bool dropItem(int slot);
    bool equipItem(int slot);
    bool unequipItem(int equipmentSlot);

    int getStrength() const;
    float getCurrentWeight() const;
    float getMaxWeight() const;

private:
    Inventory<> m_inventory;
    int m_strength;
    float m_currentWeight;

    void updateStrength();
    void updateWeight();
};
#endif //RAYLIBSTARTER_PLAYERCHAR_H
