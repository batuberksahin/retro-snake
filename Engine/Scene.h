#ifndef RETROSNAKE_SCENE_H
#define RETROSNAKE_SCENE_H

#include "../Assets/GameObject.h"

#include <vector>
#include <memory>

class Scene {
public:
    Scene() = default;

    void addGameObject(std::shared_ptr<GameObject>);
    void removeGameObject(std::shared_ptr<GameObject>);

    virtual void handleInput(unsigned char key, int x, int y) = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    std::vector<std::shared_ptr<GameObject>> _gameObjects;
};

#endif //RETROSNAKE_SCENE_H
