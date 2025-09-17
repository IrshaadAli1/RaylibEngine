#include "library.h"
#include <iostream>

inline void init() {
    using namespace std;
    preInit();
    cout << "Raylib Engine INFO: Setting up Raylib" << endl;
    cout << "Raylib Engine SETUP: Raylib" << endl;
    setupRaylibs();
    cout << "Raylib Engine INFO: Raylib Setup Complete" << endl;

    cout << "Raylib Engine SETUP: Variables" << endl;
    setupVariables();
    cout << "Raylib Engine INFO: Variables Setup Complete" << endl;
    postInit();
    cout << "Raylib Engine INFO: Starting Main Loop.." << endl;
    preMainLoop();
    while (!WindowShouldClose()) {
        events();
        update();

        preDraw();
        BeginDrawing();

        preBGFill();
        ClearBackground(Window::BG);
        postBGFill();

        preDraw3D();
        BeginMode3D(Window::Camera3D);
        draw3D();
        EndMode3D();
        postDraw3D();

        preDraw2D();
        BeginMode2D(Window::Camera2D);
        draw2D();
        EndMode2D();
        postDraw2D();

        EndDrawing();
        postDraw();

        updateWindow();
        postWindowUpdate();
    }
    cout << "Raylib Engine INFO: Exiting Program.." << endl;
}
