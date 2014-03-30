#include "scene.hpp"

#include "gameobject.hpp"

void Scene::draw() {
    for(auto& go : gameObjects_) {
        go->draw(window_);
    }
}

void Scene::update(sf::Time dt) {
    for(auto& go : gameObjects_) {
        go->update(dt);
    }
}
