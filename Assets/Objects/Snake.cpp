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

    if (checkCollision()) {
        return;
    }

    if (ateFood()) {
        addBodyPart();
    }

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
    else if (key == 'c') {
        addBodyPart();
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

bool Snake::ateFood() {
    int headX = getX();
    int headY = getY();

    if (_grid.getCellContent(headY, headX) == CellContent::Food) {
        std::cout << "Snake eated food!" << std::endl;

        _foodSpawner.removeFood(headX, headY);
        _grid.setCellContent(headY, headX, CellContent::Empty);
        addBodyPart();
        return true;
    }

    return false;
}

bool Snake::checkCollision() {
    int headX = getX();
    int headY = getY();

    for (size_t i = 1; i < _snakeBodyParts.size(); ++i) {
        if (_snakeBodyParts[i].first == headX && _snakeBodyParts[i].second == headY) {
            SceneManager::switchTo(new EndScene());
            return true;
        }
    }

    if (headX < 0 || headX >= FIXED_WINDOW_WIDTH / CELL_SIZE || headY < 0 || headY >= FIXED_WINDOW_HEIGHT / CELL_SIZE) {
        SceneManager::switchTo(new EndScene());
        return true;
    }

    return false;
}


void Snake::addBodyPart() {
    _snakeBodyParts.emplace_back(_snakeBodyParts[_snakeBodyParts.size() - 1]);

    _length++;
}