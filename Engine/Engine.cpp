#include "Engine.h"
#include "Renderer.h"

#include "../Scenes/StartScene.h"
#include "../Scenes/SceneManager.h"

#include <iostream>
#include <GL/glut.h>

// This code file are only responsible for the initialization of the game engine, creating the window and starting the game loop.
void Engine::start() {
    std::cout << "Engine started..." << std::endl;

    Engine::initializeGlutWindow();
}

void Engine::initializeGlutWindow() {
    std::cout << "Initializing GLUT window..." << std::endl;

    int argc = 1;

    char *argv[1];
    argv[0] = "RetroSnake";

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    std::pair<int, int> screenSize = Engine::getScreenSize();

    glutInitWindowSize(screenSize.first * WINDOW_SCALE, screenSize.second * WINDOW_SCALE);
    glutInitWindowPosition(
            (screenSize.first / 2) - (screenSize.first * WINDOW_SCALE / 2),
            (screenSize.second / 2) - (screenSize.second * WINDOW_SCALE / 2)
    );

    glutCreateWindow("Retro Snake");

    SceneManager::switchTo(new StartScene());

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(Renderer::render);

    glutMainLoop();
}