#ifndef SFMLSNAKE_SNAKE_HPP
#define SFMLSNAKE_SNAKE_HPP

#include <deque>

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
};

#endif // SFMLSNAKE_SNAKE_HPP
