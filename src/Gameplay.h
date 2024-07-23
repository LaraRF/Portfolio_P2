//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAY_H
#define RAYLIBSTARTER_GAMEPLAY_H

#include "Scene.h"
#include "Startscreen.h"
#include "PlayerChar.h"
#include "map.h"

class Gameplay : public Scene{
public:
    Gameplay();

    void update() override;

    Scene *evaluateSceneChange() override;

    void draw() override;

    map mapgenerator; //map = Klasse, mapgenerator = Instanz von Klasse
};


#endif //RAYLIBSTARTER_GAMEPLAY_H
