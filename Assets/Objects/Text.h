//
// Created by batuberk on 21.02.2024.
//

#ifndef RETROSNAKE_TEXT_H
#define RETROSNAKE_TEXT_H


#include "../GameObject.h"

class Text : public GameObject {
public:
    Text(int x, int y, const char *string) : GameObject(x, y) {
        _string = string;
    }

    void render() override;
    void update() override;

private:
    const char* _string;
};



#endif //RETROSNAKE_TEXT_H
