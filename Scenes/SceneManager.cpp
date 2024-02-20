#include "SceneManager.h"

Scene* SceneManager::currentScene = nullptr;

void SceneManager::switchTo(Scene* scene) {
    if (currentScene != nullptr) {
        delete currentScene;
    }

    currentScene = scene;
}

void SceneManager::updateCurrentScene() {
    if (currentScene != nullptr) {
        currentScene->update();
    }
}

void SceneManager::renderCurrentScene() {
    if (currentScene != nullptr) {
        currentScene->render();
    }
}

void SceneManager::handleInputCurrentScene(unsigned char key, int x, int y) {
    if (currentScene != nullptr) {
        currentScene->handleInput(key, x, y);
    }
}
