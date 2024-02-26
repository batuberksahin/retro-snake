#ifndef RETROSNAKE_GRAPHICS_H
#define RETROSNAKE_GRAPHICS_H

#include "../../Assets/Objects/Snake.h"

// Graphics class responsible for drawing shapes and other graphics on the screen, using OpenGL. All members are static.
class Graphics {
public:
    static void drawDebugTriangle(double);

    static void drawRectangle();

    static void drawString(int x, int y, char *string);

    static void drawSnakeHead(int x, int y, Direction direction);

    static void drawSnakeBodyPart(int posX, int posY);

    static void drawGridLines();
};


#endif //RETROSNAKE_GRAPHICS_H
