#include "snake.hpp"

Snake::Snake(sf::Vector2u boardSize) :
    timeBetweenTics_(sf::seconds(0.5f)),
    timeUntilTic_(sf::seconds(0.5f)),
    boardSize_(boardSize)
{
    name_ = "Snake";
}

void Snake::draw(sf::RenderWindow& window) {
}

void Snake::update(sf::Time dt) {
}
