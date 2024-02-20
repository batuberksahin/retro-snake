#include "GameScene.h"

#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Graphics/Timer.h"

void GameScene::render() {

    Graphics::drawRectangle();
    Graphics::drawString(-0.85f, 0.85f, "Retro Snake!");
    Graphics::drawString(0.70f, 0.85f, "Score : 0");

}

void GameScene::update() {

}

void GameScene::handleInput(unsigned char key, int x, int y) {

}