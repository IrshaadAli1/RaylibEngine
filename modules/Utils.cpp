//
// Created by Irshaad on 2025-09-09.
//
#pragma once
#include <sstream>
#include <string>
namespace Utils {
    template <typename... Args>
    inline static std::string toString(Args&&... args) {
        std::ostringstream oss;
        (oss << ... << args); // Fold expression (C++17 and above)
        return oss.str();
    }
}