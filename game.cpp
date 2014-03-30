#include "game.hpp"

#include <iostream>

#include <SFML/System/Clock.hpp>

Game::Game() {

}

int Game::run() {

    const int RETURN_SUCCESS = 0;
    const int RETURN_ERROR = -1;

    running_ = true;

    sf::Clock clock;

    try {

        while(running_) {
            scene_->handleInput();

            sf::Time time = clock.getElapsedTime();
            clock.restart();
            scene_->update(time);

            scene_->draw();
        }
    } catch(std::exception& e) {
        std::cout << "Error " << e.what() << std::endl;
        return RETURN_ERROR;
    }

    return RETURN_SUCCESS;
}

void Game::exit() {
    running_ = false;
}

void Game::setScene(std::unique_ptr<Scene> scene) {
    scene_ = std::move(scene);
}
