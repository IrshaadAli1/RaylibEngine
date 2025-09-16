//
// Created by Irshaad on 2025-09-16.
//
#pragma once
#ifndef RAYLIBENGINE_GLOBALS_H
#define RAYLIBENGINE_GLOBALS_H
#include "GlobalModules.h"

inline namespace Globals {
    namespace Window {
        inline Variable Width = Variable(0.0f);
        inline Variable Height = Variable(0.0f);
        inline Variable X = Variable(0.0f);
        inline Variable Y = Variable(0.0f);

        inline Variable Title = Variable<std::string>("Raylib Engine");
        inline Variable FPS = Variable(60);
        inline Variable BG = Variable(BLACK);

        inline float MonitorWidth = 0.0f;
        inline float MonitorHeight = 0.0f;

        inline RCamera3D Camera3D = RCamera3D();
        inline RCamera2D Camera2D = RCamera2D();
    }
}
#endif //RAYLIBENGINE_GLOBALS_H
