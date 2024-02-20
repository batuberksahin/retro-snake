#ifndef RETROSNAKE_STARTSCENE_H
#define RETROSNAKE_STARTSCENE_H

#include "../Engine/Scene.h"

class StartScene : public Scene {
public:
    void handleInput() override;
    void update() override;
    void render() override;
};

#endif //RETROSNAKE_STARTSCENE_H
