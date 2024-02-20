#include "Renderer.h"
#include "../Scenes/SceneManager.h"

#include <GL/glut.h>

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);

    SceneManager::renderCurrentScene();

    glFlush();
    glutSwapBuffers();
}

void Renderer::handleInput(unsigned char key, int x, int y) {
    SceneManager::handleInputCurrentScene(key, x, y);
}
