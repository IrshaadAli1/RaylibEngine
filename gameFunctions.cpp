//
// Created by Irshaad on 2025-09-16.
//
#pragma once
#include <functional>
using emptyFunc = std::function<void()>;

inline emptyFunc preInit = [](){};
inline emptyFunc postInit = [](){};

inline emptyFunc preMainLoop = [](){};
inline emptyFunc events = [](){};
inline emptyFunc update = [](){};

inline emptyFunc preDraw = [](){};

inline emptyFunc preBGFill = [](){};
inline emptyFunc postBGFill = [](){};

inline emptyFunc preDraw3D = [](){};
inline emptyFunc draw3D = [](){};
inline emptyFunc postDraw3D = [](){};

inline emptyFunc preDraw2D = [](){};
inline emptyFunc draw2D = [](){};
inline emptyFunc postDraw2D = [](){};

inline emptyFunc postDraw = [](){};
inline emptyFunc postWindowUpdate = [](){};
