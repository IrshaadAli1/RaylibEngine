//
// Created by Irshaad on 2025-09-16.
//
#include <functional>
using emptyFunc = std::function<void()>;

emptyFunc preInit;
emptyFunc postInit;

emptyFunc preMainLoop;
emptyFunc events;
emptyFunc update;

emptyFunc preDraw;

emptyFunc preBGFill;
emptyFunc postBGFill;

emptyFunc preDraw3D;
emptyFunc draw3D;
emptyFunc postDraw3D;

emptyFunc preDraw2D;
emptyFunc draw2D;
emptyFunc postDraw2D;

emptyFunc postDraw;
emptyFunc postWindowUpdate;
