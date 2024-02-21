#include "StartScene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

#include <iostream>

void StartScene::render() {
    Graphics::drawDebugTriangle(_time);

    Graphics::drawString(480, 350, "Retro Snake Game");
    Graphics::drawString(480, 400, "Press space to start");
}

void StartScene::update() {
    _time = _time + Timer::GetDeltaTime();
}

void StartScene::handleInput(unsigned char key, int x, int y) {
    // Press space to continue
    if (key == 32) {
        std::cout << "Switching to game scene..." << std::endl;

        SceneManager::switchTo(new GameScene());
    }
}
