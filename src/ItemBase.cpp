//
// Created by lrfri on 22.07.2024.
//

#include "ItemBase.h"

ItemBase::ItemBase(float weight, const std::string &name, const std::string &description, int price,
                   int addedstrength) {}

float ItemBase::getWeight() const { return m_weight; }
const std::string& ItemBase::getName() const { return m_name; }
const std::string& ItemBase::getDescription() const { return m_description; }
int ItemBase::getPrice() const { return m_price; }
int ItemBase::getaddedStrength() const {return m_addedstrength;}


