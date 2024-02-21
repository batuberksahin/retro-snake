#ifndef RETROSNAKE_SNAKE_H
#define RETROSNAKE_SNAKE_H

#include "../GameObject.h"

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake : public GameObject {
public:
    Snake(int x, int y) : GameObject(x, y) {
        _length = 0;

        direction = Direction::UP;
    }

    void render() override;
    void update() override;
    virtual void handleInput(unsigned char key, int x, int y) override;

private:
    int _length;
    Direction direction;
};

#endif //RETROSNAKE_SNAKE_H
