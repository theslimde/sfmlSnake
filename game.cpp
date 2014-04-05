#include "game.hpp"

#include <cassert>
#include <iostream>

#include <SFML/System/Clock.hpp>

Game::Game() :
    window_(new sf::RenderWindow(sf::VideoMode(800,600), "Snake"))
{
}

int Game::run() {

    assert(scene_);

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

            window_->clear(sf::Color::Black);
            scene_->draw();
            window_->display();
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
