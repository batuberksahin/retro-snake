#include "Snake.h"

#include "../../Engine/Graphics/Graphics.h"
#include "GridLayout.h"

#include <iostream>

void Snake::initializeBodyParts() {
    _grid.setCellContent(getY(), getX(), CellContent::Body);
    _snakeBodyParts.emplace_back(getX(), getY());

    for (int i = 1; i <= 3; ++i) {
        int bodyX = getX() - i;
        int bodyY = getY();

        _snakeBodyParts.emplace_back(bodyX, bodyY);

        _grid.setCellContent(bodyY, bodyX, CellContent::Body);
    }
}

void Snake::render() {
    auto centerPos = _grid.getCellCenterPosition(getY(), getX());
    Graphics::drawSnakeHead(centerPos.first, centerPos.second, _direction);

    for (size_t i = 1; i < _snakeBodyParts.size(); ++i) {
        const auto& part = _snakeBodyParts[i];
        centerPos = _grid.getCellCenterPosition(part.second, part.first);
        std::cout << "(" << part.first << "," << part.second << ") ";
        Graphics::drawSnakeBodyPart(centerPos.first, centerPos.second);
    }

    std::cout << std::endl;
}

void Snake::update() {
    _inputTick++;

    if (_inputTick != 10) {
        return;
    }

    _inputTick = 0;
    
    switch (_direction) {
        case Direction::UP:
            setPosition(getX(), getY() - 1);
            break;
        case Direction::DOWN:
            setPosition(getX(), getY() + 1);
            break;
        case Direction::LEFT:
            setPosition(getX() - 1, getY());
            break;
        case Direction::RIGHT:
            setPosition(getX() + 1, getY());
            break;
    }

    auto before = _snakeBodyParts[0];

    _snakeBodyParts[0] = std::make_pair(getX(), getY());

    for (int i = 1; i < _snakeBodyParts.size(); i++) {
        auto temp = _snakeBodyParts[i];
        _snakeBodyParts[i] = before;
        before = temp;
    }
}

void Snake::handleInput(unsigned char key, int x, int y) {
    if (key == 'w') {
        _direction = Direction::UP;
    }
    else if (key == 's') {
        _direction = Direction::DOWN;
    }
    else if (key == 'a') {
        _direction = Direction::LEFT;
    }
    else if (key == 'd') {
        _direction = Direction::RIGHT;
    }
}