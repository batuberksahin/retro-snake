#ifndef RETROSNAKE_SNAKE_H
#define RETROSNAKE_SNAKE_H

#include <vector>
#include "../GameObject.h"
#include "GridLayout.h"
#include "FoodSpawner.h"
#include "Text.h"

enum class Direction {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT
};

class Snake : public GameObject {
public:
    Snake(int x, int y, GridLayout &grid, FoodSpawner &foodSpawner, Text scoreText) : GameObject(x, y), _grid(grid), _foodSpawner(foodSpawner), _scoreText(scoreText) {
        _length = 0;
        _inputTick = 0;

        _direction = Direction::RIGHT;
        _directionMemo = Direction::RIGHT;

        initializeBodyParts();
    }

    void render() override;
    void update() override;
    virtual void handleInput(unsigned char key, int x, int y) override;

private:
    void initializeBodyParts();

    int _length;
    Direction _direction;

    GridLayout& _grid;
    FoodSpawner& _foodSpawner;
    Text& _scoreText;

    int _inputTick;
    Direction _directionMemo;

    // integers are represents row and col
    std::vector<std::pair<int, int>> _snakeBodyParts;

    void moveBodyParts();
    bool checkCollision();
    void addBodyPart();
    bool ateFood();
};

#endif //RETROSNAKE_SNAKE_H
