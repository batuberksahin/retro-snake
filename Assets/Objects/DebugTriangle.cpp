#include "DebugTriangle.h"

#include "../../Engine/Graphics/Graphics.h"
#include "../../Engine/Graphics/Timer.h"

void DebugTriangle::render() {
    Graphics::drawDebugTriangle(_time);
}

void DebugTriangle::update() {
    _time = _time + Timer::GetDeltaTime();
}