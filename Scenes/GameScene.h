#ifndef RETROSNAKE_GAMESCENE_H
#define RETROSNAKE_GAMESCENE_H

#include <iostream>
#include "../Engine/Scene.h"

#include "../Assets/Objects/Snake.h"
#include "../Assets/Objects/Text.h"

class GameScene : public Scene {
public:
    GameScene() : Scene() {
        _score = 0;

        _grid = std::make_shared<GridLayout>();

        _snake = std::make_shared<Snake>(7, 5, *_grid);
        _scoreText = std::make_shared<Text>(860, 50, "Score : 0");
        _gameText = std::make_shared<Text>(100, 50, "Retro Snake!");

        addGameObject(_snake);
        addGameObject(_scoreText);
        addGameObject(_gameText);
    }

    ~GameScene() {
        std::cout << "GameScene destroyed" << std::endl;
        removeGameObject(_snake);
        removeGameObject(_scoreText);
        removeGameObject(_gameText);
    }

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
    int _score;
    std::shared_ptr<Text> _scoreText;
    std::shared_ptr<Snake> _snake;
    std::shared_ptr<GridLayout> _grid;
    std::shared_ptr<Text> _gameText;
};

#endif //RETROSNAKE_GAMESCENE_H
