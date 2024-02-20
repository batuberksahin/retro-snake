#include "StartScene.h"
#include "SceneManager.h"
#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

#include <iostream>

void StartScene::render() {
    Graphics::drawDebugTriangle(_time);

    Graphics::drawString(-0.15f, -0.4f, "Retro Snake Game");
    Graphics::drawString(-0.16f, -0.5f, "Press space to start");
}

void StartScene::update() {
    _time = _time + Timer::GetDeltaTime();
    std::cout << _time << std::endl;
}

void StartScene::handleInput(unsigned char key, int x, int y) {
    // Press space to continue
    if (key == 32) {
        std::cout << "Switching to game scene..." << std::endl;

        SceneManager::switchTo(new GameScene());
    }
}
