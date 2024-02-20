#ifndef RETROSNAKE_SCENEMANAGER_H
#define RETROSNAKE_SCENEMANAGER_H

#include "../Engine/Scene.h"

class SceneManager {
public:
    static void switchTo(Scene* scene);
    static void updateCurrentScene();
    static void renderCurrentScene();

    static void handleInputCurrentScene(unsigned char key, int x, int y);

private:
    static Scene* currentScene;
};

#endif //RETROSNAKE_SCENEMANAGER_H
