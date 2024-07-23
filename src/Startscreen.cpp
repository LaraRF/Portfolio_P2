//
// Created by lrfri on 23.07.2024.
//

#include "Startscreen.h"
void Startscreen::update() {
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if (cursor == 2) {
            cursor = 2; //makes it, so you can't go "more to the right" than last box
        } else {
            cursor++;
        }
    }

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if (cursor == 0) {
            cursor = 0; //same here, but for other side of screen
        } else {
            cursor--;
        }
    }
}

Scene *Startscreen::evaluateSceneChange() { //gives the buttons their functions
    if (IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                return new Gameplay();
                break;
            case 1:
                return new Infoscreen();
                break;
            case 2:
                CloseWindow();
        }
    } else {
        return this;
    }//return this = stay on this screen (points to itself)
}

void Startscreen::draw() {

    switch (cursor) { //shows which box is selected by giving it a white outline
        case 0:
            DrawRectangleRec(hitbox_play_marked, WHITE);
            break;
        case 1:
            DrawRectangleRec(hitbox_info_marked, WHITE);
            break;
        case 2:
            DrawRectangleRec(hitbox_close_marked, WHITE);
            break;
        default:
            break;
    }
    //draws the buttons
    DrawRectangleRec(hitbox_play, GRAY);
    DrawRectangleRec(hitbox_info, GRAY);
    DrawRectangleRec(hitbox_close, GRAY);

    //draws the text on the buttons
    DrawText("PLAY", 32*1.5+25, 32*10+12.5, 20, BLUE);
    DrawText("INFO", 32*6+25, 32*10+12.5, 20, BLUE);
    DrawText("CLOSE", 32*10.5+20, 32*10+12.5,20, BLUE);

    //draws title
    DrawText("Pathfinding Game", 20,80,50,WHITE);
    DrawText("Portfolio Programmieren 2\nby Lara Friedrich", 50,150,20,WHITE);
}

Startscreen::Startscreen() {

}

