#ifndef SFMLSNAKE_SNAKE_HPP
#define SFMLSNAKE_SNAKE_HPP

#include <deque>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include "gameobject.hpp"

class Snake : public GameObject
{
public:

    Snake(sf::Vector2u boardSize);

    // draws the object in a given window
    virtual void draw(sf::RenderWindow& window) override;

    // update the gameobject
    virtual void update(sf::Time dt) override;

private:

    std::deque<sf::Vector2u> snake_;
    sf::Time timeBetweenTics_;
    sf::Time timeUntilNextTic_;
    sf::Vector2u boardSize_;
    sf::Vector2u origin_;
    sf::CircleShape snakePiece_;
    sf::CircleShape snakeHead_;
};

#endif // SFMLSNAKE_SNAKE_HPP
