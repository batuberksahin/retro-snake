#ifndef RETROSNAKE_ENDSCENE_H
#define RETROSNAKE_ENDSCENE_H


#include "../Engine/Scene.h"
#include "../Assets/Objects/DebugTriangle.h"

class EndScene : public Scene {
public:
    EndScene() : Scene() {
        addGameObject(std::make_shared<DebugTriangle>(0, 0));
    }

    ~EndScene() {}

    void handleInput(unsigned char key, int x, int y) override;
    void update() override;
    void render() override;
private:
};


#endif //RETROSNAKE_ENDSCENE_H
