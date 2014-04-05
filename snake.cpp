#include "snake.hpp"

Snake::Snake(sf::Vector2u boardSize) :
    timeBetweenTics_(sf::seconds(0.5f)),
    timeUntilNextTic_(sf::seconds(0.5f)),
    boardSize_(boardSize)
{
    name_ = "Snake";
    origin_ = sf::Vector2u(0, 768);
    snakePiece_ = sf::CircleShape(5);
    snakePiece_.setFillColor(sf::Color(100,250,50));
    snakeHead_ = sf::CircleShape(10);
    snakePiece_.setFillColor(sf::Color(255,0,0));

    sf::Vector2u start(boardSize_.x / 2, boardSize_.y / 2);
    snake_.push_back(start);
}

void Snake::draw(sf::RenderWindow& window) {
    for(auto& pos : snake_) {
        auto p = origin_ + 10u*pos;
        snakePiece_.setPosition(p.x, p.y);
        window.draw(snakePiece_);
    }
}

void Snake::update(sf::Time dt) {
}
