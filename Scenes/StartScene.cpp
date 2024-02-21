#include "StartScene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

#include <iostream>

void StartScene::render() {
    Scene::render();
}

void StartScene::update() {
    Scene::update();
}

void StartScene::handleInput(unsigned char key, int x, int y) {
    Scene::handleInput(key, x, y);

    // Press space to continue
    if (key == 32) {
        std::cout << "Switching to game scene..." << std::endl;

        SceneManager::switchTo(new GameScene());
    }
}
