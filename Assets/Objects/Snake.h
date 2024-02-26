#ifndef RETROSNAKE_SNAKE_H
#define RETROSNAKE_SNAKE_H

#include <vector>
#include "../GameObject.h"
#include "GridLayout.h"

enum class Direction {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT
};

class Snake : public GameObject {
public:
    Snake(int x, int y, GridLayout& grid) : GameObject(x, y), _grid(grid) {
        _length = 0;

        direction = Direction::RIGHT;

        initializeBodyParts();
    }

    void render() override;
    void update() override;
    virtual void handleInput(unsigned char key, int x, int y) override;

private:
    void initializeBodyParts();

    int _length;
    Direction direction;
    GridLayout& _grid;

    // integers are represents row and col
    std::vector<std::pair<int, int>> _snakeBodyParts;
};

#endif //RETROSNAKE_SNAKE_H
