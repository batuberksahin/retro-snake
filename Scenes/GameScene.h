#ifndef RETROSNAKE_GAMESCENE_H
#define RETROSNAKE_GAMESCENE_H

#include "../Engine/Scene.h"

class GameScene : public Scene {
public:
    GameScene() : Scene() {
        _score = 0;
    }

    ~GameScene() override {}

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
    int _score;
};

#endif //RETROSNAKE_GAMESCENE_H
