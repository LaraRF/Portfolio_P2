//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H

#include <vector>
#include <optional>
#include <algorithm>
#include "ItemBase.h"
#include "Sword.h"
#include "Ring.h"
#include "Shield.h"

template<typename ContainerType = std::vector<std::optional<ItemBase*>>>
class Inventory {
public:
    static constexpr int total_slots = 13;
    static constexpr int equipment_slots = 3;
    static constexpr int regular_slots = total_slots - equipment_slots;

    Inventory();
    ~Inventory();

    bool addItem(ItemBase* item, int slot = -1);
    ItemBase* removeItem(int slot);
    ItemBase* getItem(int slot) const;
    bool isFull() const;
    int getItemCount() const;

    bool equipItem(ItemBase* item);
    ItemBase* unequipItem(int equipmentSlot);
    ItemBase* getEquippedItem(int equipmentSlot) const;

private:
    ContainerType m_items;
    ContainerType m_equipmentSlots;

    bool isValidRegularSlot(int slot) const;
    bool isValidEquipmentSlot(int slot) const;
    int findEmptySlot() const;
};

// Implementation

template<typename ContainerType>
Inventory<ContainerType>::Inventory() : m_items(regular_slots), m_equipmentSlots(equipment_slots) {}

template<typename ContainerType>
Inventory<ContainerType>::~Inventory() {
    for (auto& item : m_items) {
        if (item) delete item.value();
    }
    for (auto& item : m_equipmentSlots) {
        if (item) delete item.value();
    }
}

template<typename ContainerType>
bool Inventory<ContainerType>::addItem(ItemBase* item, int slot) {
    if (isFull() && slot == -1) return false;

    if (slot == -1) {
        slot = findEmptySlot();
    } else if (!isValidRegularSlot(slot) || m_items[slot]) {
        return false;
    }

    m_items[slot] = item;
    return true;
}

template<typename ContainerType>
ItemBase* Inventory<ContainerType>::removeItem(int slot) {
    if (!isValidRegularSlot(slot) || !m_items[slot]) return nullptr;

    ItemBase* item = m_items[slot].value();
    m_items[slot].reset();
    return item;
}

template<typename ContainerType>
ItemBase* Inventory<ContainerType>::getItem(int slot) const {
    if (!isValidRegularSlot(slot) || !m_items[slot]) return nullptr;
    return m_items[slot].value();
}

template<typename ContainerType>
bool Inventory<ContainerType>::isFull() const {
    return getItemCount() == regular_slots;
}

template<typename ContainerType>
int Inventory<ContainerType>::getItemCount() const {
    return std::count_if(m_items.begin(), m_items.end(), [](const auto& item) { return item.has_value(); });
}

template<typename ContainerType>
bool Inventory<ContainerType>::equipItem(ItemBase* item) {
    int slot = -1;
    if (dynamic_cast<sword*>(item)) slot = 0;
    else if (dynamic_cast<ring*>(item)) slot = 1;
    else if (dynamic_cast<shield*>(item)) slot = 2;
    else return false;

    if (m_equipmentSlots[slot]) return false;

    m_equipmentSlots[slot] = item;
    return true;
}

template<typename ContainerType>
ItemBase* Inventory<ContainerType>::unequipItem(int equipmentSlot) {
    if (!isValidEquipmentSlot(equipmentSlot) || !m_equipmentSlots[equipmentSlot]) return nullptr;

    ItemBase* item = m_equipmentSlots[equipmentSlot].value();
    m_equipmentSlots[equipmentSlot].reset();
    return item;
}

template<typename ContainerType>
ItemBase* Inventory<ContainerType>::getEquippedItem(int equipmentSlot) const {
    if (!isValidEquipmentSlot(equipmentSlot) || !m_equipmentSlots[equipmentSlot]) return nullptr;
    return m_equipmentSlots[equipmentSlot].value();
}

template<typename ContainerType>
bool Inventory<ContainerType>::isValidRegularSlot(int slot) const {
    return slot >= 0 && slot < regular_slots;
}

template<typename ContainerType>
bool Inventory<ContainerType>::isValidEquipmentSlot(int slot) const {
    return slot >= 0 && slot < equipment_slots;
}

template<typename ContainerType>
int Inventory<ContainerType>::findEmptySlot() const {
    for (int i = 0; i < regular_slots; ++i) {
        if (!m_items[i]) return i;
    }
    return -1;
}

#endif //RAYLIBSTARTER_INVENTORY_H
