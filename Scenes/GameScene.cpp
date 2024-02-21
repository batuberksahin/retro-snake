#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

#include <string>

void GameScene::render() {
    Scene::render();

    Graphics::drawRectangle();
    Graphics::drawString(100, 50, "Retro Snake!");

    std::string scoreString = std::to_string(_score);
    std::string scoreDisplay = "Score : " + scoreString;

    Graphics::drawString(860, 50, const_cast<char *>(scoreDisplay.c_str()));
}

void GameScene::update() {
    Scene::update();
}

void GameScene::handleInput(unsigned char key, int x, int y) {

}