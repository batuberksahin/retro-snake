#ifndef RETROSNAKE_ENGINE_H
#define RETROSNAKE_ENGINE_H

#include <utility>

#define WINDOW_SCALE 0.5

class Engine {
public:
    static void start();
private:
    static void initializeGlutWindow();

    static std::pair<int, int> getScreenSize();
};

#endif //RETROSNAKE_ENGINE_H
