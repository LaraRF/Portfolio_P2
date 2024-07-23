//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_STARTSCREEN_H
#define RAYLIBSTARTER_STARTSCREEN_H

#include "Scene.h"
#include "Infoscreen.h"
#include "Gameplay.h"

class Startscreen : public Scene {

public:
    int cursor = 0;

    Startscreen();

    void update() override;

    Scene *evaluateSceneChange() override;

    void draw() override;


    //creates the boxes that will be used as buttons; marked boxes are to create an outline that shows which button is selected
    Rectangle hitbox_play = {32*1.5, 32*10, 100, 50};
    Rectangle hitbox_play_marked = {32*1.5-10, 31*10, 120, 70};

    Rectangle hitbox_info = {32*6, 32*10, 100, 50};
    Rectangle hitbox_info_marked = {32*6-10, 31*10, 120, 70};

    Rectangle hitbox_close = {32*10.5, 32*10, 100, 50};
    Rectangle hitbox_close_marked = {32*10.5-10, 31*10, 120, 70};
};


#endif //RAYLIBSTARTER_STARTSCREEN_H
