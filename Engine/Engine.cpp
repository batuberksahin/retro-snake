#include "Engine.h"
#include "Renderer.h"
#include "Config.h"

#include "../Scenes/StartScene.h"
#include "../Scenes/SceneManager.h"

#include "Graphics/Timer.h"

#include <iostream>
#include <GL/glut.h>

// This code file are only responsible for the initialization of the game engine, creating the window, set up the timer and starting the game loop.
void Engine::start() {
    std::cout << "Engine started..." << std::endl;

    Timer::Initialize();
    Engine::initializeGlutWindow();
}

void Engine::initializeGlutWindow() {
    std::cout << "Initializing GLUT window..." << std::endl;

    int argc = 1;

    char *argv[1];
    argv[0] = "RetroSnake";

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

#if USE_FIXED_WINDOW_SIZE
    glutInitWindowSize(FIXED_WINDOW_WIDTH, FIXED_WINDOW_HEIGHT);

    glutInitWindowPosition(
            FIXED_WINDOW_WIDTH - (FIXED_WINDOW_WIDTH / 2),
            FIXED_WINDOW_HEIGHT - (FIXED_WINDOW_HEIGHT / 2)
    );
#else
    std::pair<int, int> screenSize = Engine::getScreenSize();
    glutInitWindowSize(screenSize.first * WINDOW_SCALE, screenSize.second * WINDOW_SCALE);

    glutInitWindowPosition(
            screenSize.first / 2 - (screenSize.first * WINDOW_SCALE / 2),
            screenSize.second / 2 - (screenSize.second * WINDOW_SCALE / 2)
    );
#endif

    glutCreateWindow("Retro Snake");

    SceneManager::switchTo(new StartScene());

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(Renderer::render);
    glutKeyboardFunc(Renderer::handleInput);

    glutTimerFunc(INTERVAL, timer, 0);

    glutMainLoop();
}

void Engine::timer(int time) {
    Timer::Update();

    SceneManager::updateCurrentScene();

    glutPostRedisplay();

    glutTimerFunc(INTERVAL, timer, 0);
}