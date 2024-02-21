#ifndef RETROSNAKE_GRAPHICS_H
#define RETROSNAKE_GRAPHICS_H

// Graphics class responsible for drawing shapes and other graphics on the screen, using OpenGL. All members are static.
class Graphics {
public:
    static void drawDebugTriangle(double);

    static void drawRectangle();

    static void drawString(int x, int y, char *string);
};


#endif //RETROSNAKE_GRAPHICS_H
