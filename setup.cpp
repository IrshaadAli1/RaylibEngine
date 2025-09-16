//
// Created by Irshaad on 2025-09-16.
//
#pragma once
#include "Globals.h"

inline void setupRaylibs() {
    InitWindow(0, 0, "");
    InitAudioDevice();

    SetTargetFPS(60);
    SetExitKey(KEY_ESCAPE);
}

inline void setupVariables() {
    int monitor = GetCurrentMonitor();
    Window::MonitorWidth = (float) GetMonitorWidth(monitor);
    Window::MonitorHeight = (float) GetMonitorHeight(monitor);

    Window::Width = Window::MonitorWidth / 2.0f;
    Window::Height = Window::MonitorHeight / 2.0f;

    Window::X = Window::MonitorWidth / 4.0f;
    Window::Y = Window::MonitorHeight / 4.0f;

    Window::Title = "Raylib Engine Template";
    Window::FPS = 60;
}

inline void updateWindow() {
    if (Window::X.isChanged() || Window::Y.isChanged()) {
        SetWindowPosition((int) Window::X, (int) Window::Y);
    }
    if (Window::Width.isChanged() || Window::Height.isChanged()) {
        SetWindowSize((int) Window::Width, (int) Window::Height);
    }
    if (Window::Title.isChanged()) {
        SetWindowTitle(Window::Title.get().c_str());
    }
    if (Window::FPS.isChanged()) {
        SetTargetFPS(Window::FPS);
    }
    updateVars();
}
