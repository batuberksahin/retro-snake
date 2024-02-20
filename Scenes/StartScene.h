#ifndef RETROSNAKE_STARTSCENE_H
#define RETROSNAKE_STARTSCENE_H

#include "../Engine/Scene.h"

class StartScene : public Scene {
public:
    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
    int _score = { 0 };
    double _time = { 0.0f };
};

#endif //RETROSNAKE_STARTSCENE_H
