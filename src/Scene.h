//
// Created by lrfri on 23.07.2024.
//

#ifndef RAYLIBSTARTER_SCENE_H
#define RAYLIBSTARTER_SCENE_H

#include <vector>
#include "raylib.h"

class Scene {
public:
    virtual void update() = 0;
    virtual Scene* evaluateSceneChange()=0;
    virtual void draw() = 0;
};

#endif //RAYLIBSTARTER_SCENE_H
