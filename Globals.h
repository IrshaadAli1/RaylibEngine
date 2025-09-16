//
// Created by Irshaad on 2025-09-16.
//
#pragma once
#ifndef RAYLIBENGINE_GLOBALS_H
#define RAYLIBENGINE_GLOBALS_H
#include "GlobalModules.h"

inline namespace Globals {
    namespace Window {
        Variable Width = Variable(0.0f);
        Variable Height = Variable(0.0f);
        Variable X = Variable(0.0f);
        Variable Y = Variable(0.0f);

        Variable Title = Variable<std::string>("Raylib Engine");
        Variable FPS = Variable(60);
        Variable BG = Variable(BLACK);

        float MonitorWidth = 0.0f;
        float MonitorHeight = 0.0f;

        RCamera3D Camera3D = RCamera3D();
        RCamera2D Camera2D = RCamera2D();
    }
}
#endif //RAYLIBENGINE_GLOBALS_H
