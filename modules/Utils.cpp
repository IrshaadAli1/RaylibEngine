//
// Created by Irshaad on 2025-09-09.
//
#pragma once
#include <sstream>
#include <string>
#include <initializer_list>
#include <raylib-cpp.hpp>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

inline namespace Utils {
    template <typename... Args>
    inline static std::string toString(Args&&... args) {
        std::ostringstream oss;
        (oss << ... << args); // Fold expression (C++17 and above)
        return oss.str();
    }

    template <typename RealType = double>
    inline static RealType random() {
        std::uniform_real_distribution<RealType>dist(0, 1);
        return dist(gen);
    }
    template <typename RealType = double>
    inline static RealType random(RealType bound) {
        std::uniform_real_distribution<RealType>dist(bound);
        return dist(gen);
    }
    template <typename RealType = double>
    inline static RealType random(RealType start, RealType bound) {
        std::uniform_real_distribution<RealType>dist(start, bound);
        return dist(gen);
    }


    namespace Keys {
        inline static bool OrKeysDown(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (IsKeyDown(k)) {
                    return true;
                }
            }
            return false;
        }

        inline static bool AllKeysDown(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (!IsKeyDown(k)) {
                    return false;
                }
            }
            return true;
        }

        inline static bool OrKeysPressed(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (IsKeyPressed(k)) {
                    return true;
                }
            }
            return false;
        }

        inline static bool AllKeysPressed(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (!IsKeyPressed(k)) {
                    return false;
                }
            }
            return true;
        }

        inline static bool OrKeysUp(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (IsKeyUp(k)) {
                    return true;
                }
            }
            return false;
        }

        inline static bool AllKeysUp(std::initializer_list<KeyboardKey> Keys) {
            for (KeyboardKey k: Keys) {
                if (!IsKeyUp(k)) {
                    return false;
                }
            }
            return true;
        }
    }
}