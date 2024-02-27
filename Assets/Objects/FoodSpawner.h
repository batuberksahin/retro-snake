#ifndef RETROSNAKE_FOODSPAWNER_H
#define RETROSNAKE_FOODSPAWNER_H

#include "../GameObject.h"
#include "GridLayout.h"

class FoodSpawner : public GameObject {
public:
    FoodSpawner(int x, int y, GridLayout &grid) : GameObject(x, y), _grid(grid) {

    }

    void render() override;
    void update() override;
    virtual void handleInput(unsigned char key, int x, int y) override;

    void removeFood(int x, int y);
private:
    std::vector<std::pair<int, int>> _spawnedFoods;

    double _spawnTimer = 0.0f;

    GridLayout& _grid;

    void spawnFood();
};

#endif //RETROSNAKE_FOODSPAWNER_H
