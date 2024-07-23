//
// Created by lrfri on 23.07.2024.
//

#include "PlayerChar.h"
#include "Sword.h"
#include "Ring.h"
#include "Shield.h"

PlayerChar::PlayerChar(int x, int y, int strength)
        : Character(x, y), m_strength(strength), m_currentWeight(0) {}

bool PlayerChar::move(int dx, int dy) {
    if (m_currentWeight > getMaxWeight()) {
        return false;  // Too heavy to move
    }
    m_x += dx;
    m_y += dy;
    return true;
}

bool PlayerChar::pickUpItem(ItemBase* item) {
    if (m_inventory.addItem(item)) {
        updateWeight();
        updateStrength();
        return true;
    }
    return false;
}

bool PlayerChar::dropItem(int slot) {
    ItemBase* item = m_inventory.removeItem(slot);
    if (item) {
        updateWeight();
        updateStrength();
        return true;
    }
    return false;
}

bool PlayerChar::equipItem(int slot) {
    ItemBase* item = m_inventory.getItem(slot);
    if (item && m_inventory.equipItem(item)) {
        m_inventory.removeItem(slot);
        updateStrength();
        return true;
    }
    return false;
}

bool PlayerChar::unequipItem(int equipmentSlot) {
    ItemBase* item = m_inventory.unequipItem(equipmentSlot);
    if (item && m_inventory.addItem(item)) {
        updateStrength();
        return true;
    }
    return false;
}

int PlayerChar::getStrength() const {
    return m_strength;
}

float PlayerChar::getCurrentWeight() const {
    return m_currentWeight;
}

float PlayerChar::getMaxWeight() const {
    return m_strength * 2.0f;
}

void PlayerChar::updateStrength() {
    int addedStrength = 0;
    for (int i = 0; i < m_inventory.equipment_slots; ++i) {
        ItemBase* item = m_inventory.getEquippedItem(i);
        if (item) {
            if (Sword* sword = dynamic_cast<Sword*>(item)) {
                addedStrength += sword->getaddedStrength();
            } else if (Ring* ring = dynamic_cast<Ring*>(item)) {
                addedStrength += ring->getaddedStrength();
            } else if (Shield* shield = dynamic_cast<Shield*>(item)) {
                addedStrength += shield->getaddedStrength();
            }
        }
    }
    m_strength += addedStrength;
}

void PlayerChar::updateWeight() {
    m_currentWeight = 0;
    for (int i = 0; i < m_inventory.total_slots; ++i) {
        ItemBase* item = m_inventory.getItem(i);
        if (item) {
            m_currentWeight += item->getWeight();
        }
    }
    for (int i = 0; i < m_inventory.equipment_slots; ++i) {
        ItemBase* item = m_inventory.getEquippedItem(i);
        if (item) {
            m_currentWeight += item->getWeight();
        }
    }
}
