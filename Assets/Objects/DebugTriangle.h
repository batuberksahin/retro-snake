#ifndef RETROSNAKE_DEBUGTRIANGLE_H
#define RETROSNAKE_DEBUGTRIANGLE_H

#include "../GameObject.h"

class DebugTriangle : public GameObject {
public:
    DebugTriangle(int x, int y) : GameObject() {
        setPosition(x, y);

        _time = 0.0f;
    }

    void render() override;
    void update() override;

private:
    double _time;
};

#endif //RETROSNAKE_DEBUGTRIANGLE_H
