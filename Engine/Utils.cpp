#include "Engine.h"

#include <GL/glut.h>

#include <iostream>
#include <utility>

std::pair<int, int> Engine::getScreenSize() {
    std::cout << "Getting screen size..." << std::endl;

    int width = glutGet(GLUT_SCREEN_WIDTH);
    int height = glutGet(GLUT_SCREEN_HEIGHT);

    std::cout << "Screen size: " << width << ", " << height << std::endl;

    return std::make_pair(width, height);
}