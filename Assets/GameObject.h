#ifndef RETROSNAKE_GAMEOBJECT_H
#define RETROSNAKE_GAMEOBJECT_H

class GameObject {
public:
    GameObject(int x = 0, int y = 0) {
        _x = x;
        _y = y;
    }

    virtual ~GameObject() {

    }

    virtual void render() = 0;
    virtual void update() = 0;
    virtual void handleInput(unsigned char key, int x, int y) = 0;

    void setPosition(int x, int y) {
        _x = x;
        _y = y;
    }
private:
    int _x, _y;

protected:
    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }
};

#endif //RETROSNAKE_GAMEOBJECT_H
