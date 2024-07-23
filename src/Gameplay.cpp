//
// Created by lrfri on 23.07.2024.
//

#include "Gameplay.h"

void Gameplay::update() {
// Create a player at position (0, 0) with base strength 10
    PlayerChar player(0, 0, 10);

}

Scene *Gameplay::evaluateSceneChange() {
    if (IsKeyPressed(KEY_M)) {
        return new Startscreen();
        }
    else {
        return this;
    }//return this = stay on this screen (points to itself);
}

void Gameplay::draw() {
    ClearBackground(GRAY);

    mapgenerator.drawMap(Game::ScreenWidth, Game::ScreenHeight); //ruft Funkktion auf, die map drawt
    if (IsKeyPressed(KEY_R)) { //wenn man R drückt, mach neue Map
        mapgenerator.generateMap();
    }
}


Gameplay::Gameplay() {
    mapgenerator.generateMap(); //ruft Funktion auf, die Map erstellt

}
