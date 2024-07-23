﻿#include <cstdlib>
#include <algorithm>
#include <cmath>
#include "raylib.h"

#include "config.h"
#include "map.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, "Portfolio_Programming2");
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here

    RenderTexture2D canvas = LoadRenderTexture(Game::ScreenWidth, Game::ScreenHeight);
    float renderScale{}; // this and the line below are relevant to drawing later.
    Rectangle renderRec{};

    map mapgenerator; //map = Klasse, mapgenerator = Instanz von Klasse
    mapgenerator.generateMap(); //ruft Funktion auf, die Map erstellt

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_ENTER)) { //Fullscreen logic.
            if (IsWindowFullscreen()) {
                ToggleFullscreen();
                SetWindowSize(Game::ScreenWidth,Game::ScreenHeight);
            } else {
                SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
                ToggleFullscreen();
            }
        }
        // Updates that are made by frame are coded here
        // This is where YOUR logic code should go

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // For the letterbox we draw on canvas instad
        BeginTextureMode(canvas);
        { //Within this block is where we draw our app to the canvas and YOUR code goes.
            ClearBackground(WHITE);
            mapgenerator.drawMap(Game::ScreenWidth, Game::ScreenHeight); //ruft Funkktion auf, die map drawt
            if (IsKeyPressed(KEY_R)) { //wenn man R drückt, mach neue Map
                mapgenerator.generateMap();
            }
        }
        EndTextureMode();
        //The following lines put the canvas in the middle of the window and have the negative as black
        ClearBackground(BLACK); // If you want something else than a black void in the background
                                // then you can add stuff here.

        renderScale = std::min(GetScreenHeight() / (float) canvas.texture.height, // Calculates how big or small the canvas has to be rendered.
                               GetScreenWidth()  / (float) canvas.texture.width); // Priority is given to the smaller side.
        renderScale = floorf(renderScale);
        if (renderScale < 1) renderScale = 1; // Ensure that scale is at least 1.
        renderRec.width = canvas.texture.width * renderScale;
        renderRec.height = canvas.texture.height * renderScale;
        renderRec.x = (GetScreenWidth() - renderRec.width) / 2.0f;
        renderRec.y = (GetScreenHeight() - renderRec.height) / 2.0f;
        DrawTexturePro(canvas.texture,
                       Rectangle{0, 0, (float) canvas.texture.width, (float) -canvas.texture.height},
                       renderRec,
                       {}, 0, WHITE);
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_S)) {
            DrawText(TextFormat("Render scale: %.0f", renderScale), 10, 10, 20, LIGHTGRAY);
        }
        EndDrawing();
    } // Main game loop end

    // De-initialization here

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
