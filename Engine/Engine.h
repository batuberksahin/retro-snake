#ifndef RETROSNAKE_ENGINE_H
#define RETROSNAKE_ENGINE_H

#include <utility>

#define WINDOW_SCALE 0.5

class Engine {
public:
    static void start();
private:
    static const int FPS = 60;
    static const int INTERVAL = 1000 / FPS;

    static void initializeGlutWindow();
    static void timer(int);

    static std::pair<int, int> getScreenSize();
};

#endif //RETROSNAKE_ENGINE_H
