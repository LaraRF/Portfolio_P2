//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_INFOSCREEN_H
#define RAYLIBSTARTER_INFOSCREEN_H

#include "Scene.h"
#include "Startscreen.h"

class Infoscreen :public Scene {

public:
    Infoscreen();

    void update() override;

    Scene *evaluateSceneChange() override;

    void draw() override;

};


#endif //RAYLIBSTARTER_INFOSCREEN_H
