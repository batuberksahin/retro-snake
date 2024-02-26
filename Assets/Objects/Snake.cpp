#include "Snake.h"

#include "../../Engine/Graphics/Graphics.h"
#include "GridLayout.h"

#include <iostream>

void Snake::initializeBodyParts() {
    _grid.setCellContent(getY(), getX(), CellContent::Body);

    for (int i = 1; i <= 3; ++i) {
        int bodyX = getX() - i;
        int bodyY = getY();

        _snakeBodyParts.emplace_back(bodyX, bodyY);

        _grid.setCellContent(bodyY, bodyX, CellContent::Body);
    }

}

void Snake::render() {
    auto centerPos = _grid.getCellCenterPosition(getY(), getX());
    std::cout << "row: " << getY() << ", col: " << getX() << std::endl;
    std::cout << centerPos.first << ", " << centerPos.second << std::endl;
    Graphics::drawSnakeHead(centerPos.first, centerPos.second, direction);

    for (const auto& part : _snakeBodyParts) {
        centerPos = _grid.getCellCenterPosition(part.second, part.first);
        Graphics::drawSnakeBodyPart(centerPos.first, centerPos.second);
    }
}

void Snake::update() {
    return;

    switch (direction) {
        case Direction::UP:
            setPosition(getX(), getY() + 1);
            break;
        case Direction::DOWN:
            setPosition(getX(), getY() - 1);
            break;
        case Direction::LEFT:
            setPosition(getX() - 1, getY());
            break;
        case Direction::RIGHT:
            setPosition(getX() + 1, getY());
            break;
    }

    for (int i = _snakeBodyParts.size() - 1; i > 0; --i) {
        _snakeBodyParts[i] = _snakeBodyParts[i - 1];
    }

    _snakeBodyParts[0] = std::make_pair(getX(), getY());
}

void Snake::handleInput(unsigned char key, int x, int y) {
    if (key == 'w') {
        direction = Direction::UP;
    }
    else if (key == 's') {
        direction = Direction::DOWN;
    }
    else if (key == 'a') {
        direction = Direction::LEFT;
    }
    else if (key == 'd') {
        direction = Direction::RIGHT;
    }
}