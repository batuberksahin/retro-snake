#include "StartScene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"

#include <iostream>

void StartScene::render() {
    Graphics::drawDebugTriangle();
}

void StartScene::update() {

}

void StartScene::handleInput(unsigned char key, int x, int y) {
    // Press space to continue
    if (key == 32) {
        std::cout << "Switching to game scene..." << std::endl;

        SceneManager::switchTo(new GameScene());
    }
}
