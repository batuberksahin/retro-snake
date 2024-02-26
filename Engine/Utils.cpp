#include "Engine.h"
#include "Config.h"

#include <GL/glut.h>

#include <iostream>
#include <utility>

std::pair<int, int> Engine::getScreenSize() {
    int width = glutGet(GLUT_SCREEN_WIDTH);
    int height = glutGet(GLUT_SCREEN_HEIGHT);

    return std::make_pair(width, height);
}

std::pair<float, float> Engine::screenPositionToGLCoordinate(int x, int y) {
#if USE_FIXED_WINDOW_SIZE
    int windowWidth = FIXED_WINDOW_WIDTH;
    int windowHeight = FIXED_WINDOW_HEIGHT;
#else
    std::pair<int, int> screenSizes = Engine::getScreenSize();

        int windowWidth = screenSizes.first * WINDOW_SCALE;
        int windowHeight = screenSizes.second * WINDOW_SCALE;
#endif

    float normalizedX = (2.0f * x) / windowWidth - 1.0f;
    float normalizedY = 1.0f - (2.0f * y) / windowHeight;

    return std::make_pair(normalizedX, normalizedY);
}