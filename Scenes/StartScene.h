#ifndef RETROSNAKE_STARTSCENE_H
#define RETROSNAKE_STARTSCENE_H

#include "../Engine/Scene.h"

#include "../Assets/Objects/DebugTriangle.h"
#include "../Assets/Objects/Text.h"

class StartScene : public Scene {
public:
    StartScene() : Scene() {
        addGameObject(std::make_shared<DebugTriangle>(0, 0));
        addGameObject(std::make_shared<Text>(480, 350, "Retro Snake Game"));
        addGameObject(std::make_shared<Text>(480, 400, "Press space to start"));
    }

    ~StartScene() override {}

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
};

#endif //RETROSNAKE_STARTSCENE_H
