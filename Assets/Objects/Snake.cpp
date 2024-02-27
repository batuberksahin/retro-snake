#include "Snake.h"

#include "../../Engine/Graphics/Graphics.h"
#include "GridLayout.h"
#include "../../Scenes/SceneManager.h"
#include "../../Scenes/EndScene.h"

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

        Graphics::drawSnakeBodyPart(centerPos.first, centerPos.second);
    }
}

void Snake::update() {
    _inputTick++;

    if (_inputTick != 10) {
        return;
    }

    _inputTick = 0;

    _direction = _directionMemo;

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

    bool isCollided = checkCollision();
    if (isCollided) return;

    moveBodyParts();
}

void Snake::handleInput(unsigned char key, int x, int y) {
    if (key == 'w' && _direction != Direction::DOWN) {
        _directionMemo = Direction::UP;
    }
    else if (key == 's' && _direction != Direction::UP) {
        _directionMemo = Direction::DOWN;
    }
    else if (key == 'a' && _direction != Direction::RIGHT) {
        _directionMemo = Direction::LEFT;
    }
    else if (key == 'd' && _direction != Direction::LEFT) {
        _directionMemo = Direction::RIGHT;
    }
}

void Snake::moveBodyParts() {
    auto before = _snakeBodyParts[0];

    _snakeBodyParts[0] = std::make_pair(getX(), getY());
    _grid.setCellContent(getY(), getX(), CellContent::Body);

    for (int i = 1; i < _snakeBodyParts.size(); i++) {
        if (i == _snakeBodyParts.size() - 1) {
            _grid.setCellContent(_snakeBodyParts[i].second, _snakeBodyParts[i].first, CellContent::Empty);
        }

        auto temp = _snakeBodyParts[i];
        _snakeBodyParts[i] = before;
        _grid.setCellContent(before.second, before.first, CellContent::Body);
        before = temp;
    }
}

bool Snake::checkCollision() {
    if (getX() < 0 || getX() >= FIXED_WINDOW_WIDTH / CELL_SIZE || getY() < 0 || getY() >= FIXED_WINDOW_HEIGHT / CELL_SIZE) {
        std::cout << "Game Over!" << std::endl;

        SceneManager::switchTo(new EndScene());
        return true;
    }

    return false;
}
