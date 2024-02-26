#ifndef RETROSNAKE_SNAKE_H
#define RETROSNAKE_SNAKE_H

#include <vector>
#include "../GameObject.h"

enum class Direction {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT
};

class Snake : public GameObject {
public:
    Snake(int x, int y) : GameObject(x, y) {
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

    std::vector<std::pair<int, int>> _snakeBodyParts;
};

#endif //RETROSNAKE_SNAKE_H
