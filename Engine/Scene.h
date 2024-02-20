#ifndef RETROSNAKE_SCENE_H
#define RETROSNAKE_SCENE_H

class Scene {
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual ~Scene() = default;
};

#endif //RETROSNAKE_SCENE_H
