#ifndef RETROSNAKE_GAMESCENE_H
#define RETROSNAKE_GAMESCENE_H

#include "../Engine/Scene.h"

class GameScene : public Scene {
public:
    void handleInput() override;
    void update() override;
    void render() override;
};

#endif //RETROSNAKE_GAMESCENE_H
