#ifndef RETROSNAKE_ENDSCENE_H
#define RETROSNAKE_ENDSCENE_H


#include "../Engine/Scene.h"

class EndScene : public Scene {
public:
    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
};


#endif //RETROSNAKE_ENDSCENE_H
