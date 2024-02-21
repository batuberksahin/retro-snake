#ifndef RETROSNAKE_GAMESCENE_H
#define RETROSNAKE_GAMESCENE_H

#include "../Engine/Scene.h"

#include "../Assets/Objects/Snake.h"
#include "../Assets/Objects/Text.h"

class GameScene : public Scene {
public:
    GameScene() : Scene() {
        _score = 0;

        _snake = std::make_shared<Snake>(480, 270);

        _scoreText = std::make_shared<Text>(860, 50, "Score : 0");

        addGameObject(_snake);
        addGameObject(_scoreText);

        addGameObject(std::make_shared<Text>(100, 50, "Retro Snake!"));
    }

    ~GameScene() override {}

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
    int _score;
    std::shared_ptr<Text> _scoreText;
    std::shared_ptr<Snake> _snake;
};

#endif //RETROSNAKE_GAMESCENE_H
