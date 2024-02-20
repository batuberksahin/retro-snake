#include "Timer.h"

std::chrono::steady_clock::time_point Timer::lastFrameTime;
std::chrono::steady_clock::time_point Timer::currentFrameTime;
float Timer::deltaTime;

void Timer::Initialize() {
    lastFrameTime = std::chrono::steady_clock::now();
    currentFrameTime = std::chrono::steady_clock::now();
    deltaTime = 0.0f;
}

void Timer::Update() {
    lastFrameTime = currentFrameTime;
    currentFrameTime = std::chrono::steady_clock::now();

    deltaTime = std::chrono::duration<float, std::chrono::milliseconds::period>(currentFrameTime - lastFrameTime).count() / 1000.0f;
}

float Timer::GetDeltaTime() {
    return deltaTime;
}
