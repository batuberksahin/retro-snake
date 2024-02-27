#ifndef RETROSNAKE_TIMER_H
#define RETROSNAKE_TIMER_H

#include <chrono>

class Timer {
public:
    static void Initialize();
    static void Update();

    static float GetDeltaTime();

private:
    static std::chrono::steady_clock::time_point lastFrameTime;
    static std::chrono::steady_clock::time_point currentFrameTime;
    static float deltaTime;

    float GetDeltaTimeInMs();
};

#endif //RETROSNAKE_TIMER_H
