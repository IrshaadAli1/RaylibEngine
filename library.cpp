#include "library.h"

inline void init() {
    preInit();
    setupRaylibs();
    setupVariables();
    updateWindow();
    postInit();

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
}
