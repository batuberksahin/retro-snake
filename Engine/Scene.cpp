#include "Scene.h"

#include <iostream>
#include <algorithm>

void Scene::addGameObject(std::shared_ptr<GameObject> gameObject) {
    _gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(std::shared_ptr<GameObject> gameObject) {
    _gameObjects.erase(std::remove_if(_gameObjects.begin(), _gameObjects.end(),
                                      [gameObject](const auto& obj) {
                                          return obj == gameObject;
                                      }), _gameObjects.end());
}

void Scene::render() {
    for (auto& gameObject : _gameObjects) {
        gameObject->render();
    }
}

void Scene::update() {
    for (auto& gameObject : _gameObjects) {
        gameObject->update();
    }
}

void Scene::handleInput(unsigned char key, int x, int y) {
    for (auto& gameObject : _gameObjects) {
        gameObject->handleInput(key, x, y);
    }
}
