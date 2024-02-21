#include "DebugTriangle.h"

#include "../../Engine/Graphics/Graphics.h"
#include "../../Engine/Graphics/Timer.h"

void DebugTriangle::render() {
    Graphics::drawDebugTriangle(_time);
}

void DebugTriangle::update() {
    _time = _time + Timer::GetDeltaTime();
}

void DebugTriangle::handleInput(unsigned char key, int x, int y) {

}
