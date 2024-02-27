#include <cstdlib>
#include <iostream>
#include "FoodSpawner.h"
#include "GridLayout.h"

#include "../../Engine/Graphics/Timer.h"
#include "../../Engine/Graphics/Graphics.h"

void FoodSpawner::render() {
    for (const auto& foodPos : _spawnedFoods) {
        Graphics::drawFood(foodPos.first, foodPos.second);
    }
}

void FoodSpawner::update() {
    _spawnTimer += Timer::GetDeltaTime();

    if (_spawnTimer >= 5.0f) {
        _spawnTimer = 0;

        spawnFood();
    }

}

void FoodSpawner::handleInput(unsigned char key, int x, int y) {

}

void FoodSpawner::spawnFood() {
    int foodX = rand() % FIXED_WINDOW_WIDTH / CELL_SIZE;
    int foodY = rand() % FIXED_WINDOW_HEIGHT / CELL_SIZE;


    if (_grid.getCellContent(foodX, foodY) == CellContent::Empty) {
        std::cout << "Food spawned on " << foodX << ", " << foodY << std::endl;

        _grid.setCellContent(foodX, foodY, CellContent::Food);
        _spawnedFoods.emplace_back(foodX, foodY);
    }
    else {
        spawnFood();
    }
}

void FoodSpawner::removeFood(int x, int y) {
    for (auto it = _spawnedFoods.begin(); it != _spawnedFoods.end(); ++it) {
        if (it->first == x && it->second == y) {
            _spawnedFoods.erase(it);
            _grid.setCellContent(x, y, CellContent::Empty);
            return;
        }
    }
}