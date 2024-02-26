#include "Snake.h"

#include "../../Engine/Graphics/Graphics.h"

#include <iostream>

void Snake::initializeBodyParts() {

}

void Snake::render() {
    Graphics::drawSnakeHead(getX(), getY(), direction);

    for (const auto& part : _snakeBodyParts) {
    //    Graphics::drawSnakeBodyPart(part.first, part.second);
    }
}

void Snake::update() {

}

void Snake::handleInput(unsigned char key, int x, int y) {
    if (key == 'w') {
        std::cout << "Up arrow key pressed" << std::endl;
    }
    else if (key == 's') {
        std::cout << "Down arrow key pressed" << std::endl;
    }
    else if (key == 'a') {
        std::cout << "Left arrow key pressed" << std::endl;
    }
    else if (key == 'd') {
        std::cout << "Right arrow key pressed" << std::endl;
    }
}