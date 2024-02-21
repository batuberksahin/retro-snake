#ifndef RETROSNAKE_GAMESCENE_H
#define RETROSNAKE_GAMESCENE_H

#include "../Engine/Scene.h"

#include "../Assets/Objects/Snake.h"
#include "../Assets/Objects/Text.h"

class GameScene : public Scene {
public:
    GameScene() : Scene() {
        _score = 0;

        _scoreText = std::make_shared<Text>(860, 50, "Score : 0");

        addGameObject(std::make_shared<Snake>(480, 270));
        addGameObject(std::make_shared<Text>(100, 50, "Retro Snake!"));
        addGameObject(_scoreText);
    }

    ~GameScene() override {}

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
    int _score;
    std::shared_ptr<Text> _scoreText;
};

#endif //RETROSNAKE_GAMESCENE_H
