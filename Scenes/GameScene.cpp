#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

void GameScene::render() {
    Scene::render();

#if USE_GRID_LINES
    Graphics::drawGridLines();
#endif
}

void GameScene::update() {
    Scene::update();
}

void GameScene::handleInput(unsigned char key, int x, int y) {
    Scene::handleInput(key, x, y);
}