#ifndef RETROSNAKE_RENDERER_H
#define RETROSNAKE_RENDERER_H

#include "Scene.h"

class Renderer {
public:
    static void render();

    static void handleInput(unsigned char, int, int);
};

#endif //RETROSNAKE_RENDERER_H
