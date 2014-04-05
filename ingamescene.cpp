#include "ingamescene.hpp"

#include "snake.hpp"

InGameScene::InGameScene(std::uint8_t sizeX, std::uint8_t sizeY,
            std::string nameOfPlayer, sf::RenderWindow& window,
            Game& game) :
    Scene(window, game),
    boardSize_(sizeX, sizeY),
    nameOfPlayer_(nameOfPlayer),
    origin_(0,0),
    fieldSize_(0,0)
{
    // Setup a view of the size 1024x768 to display the information
    // such as Player name, score etc.
    const sf::Vector2u screenSize(1024, 768);
    screenView_ = sf::View(sf::FloatRect(0, 0, screenSize.x, screenSize.y));

    // Setup a view to display the board
    const std::uint32_t fieldSize = 20;
    const sf::Vector2u boardSize(sizeX * fieldSize, sizeY * fieldSize);
    boardView_ = sf::View(sf::FloatRect(0, screenSize.y,
                boardSize.x, boardSize.y));

    // FIXME: Get make_unique to work!
    gameObjects_.emplace_back(new Snake(boardSize_));
}

void InGameScene::update(sf::Time dt) {
}

void InGameScene::handleInput() {
}

void InGameScene::draw() {
    window_.setView(screenView_);

    window_.setView(boardView_);
    for(auto& obj : gameObjects_) {
        obj->draw(window_);
    }
}
