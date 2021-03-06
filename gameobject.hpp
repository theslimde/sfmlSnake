#ifndef SFMLSNAKE_GAMEOBJECT_HPP
#define SFMLSNAKE_GAMEOBJECT_HPP

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

/*
 * GameObject is a super class for every object within the game.
 * It is a abstract class that provides a few convenient
 * inline funcions such as draw(). These can be overridden by
 * a subclass.
 */
class GameObject
{
public:
    // Virtual Dtor
    virtual ~GameObject() {
    }

    // draws the object in a given window
    virtual void draw(sf::RenderWindow& window) = 0;

    // gets the name of the object
    virtual const std::string getName() const {
        return name_;
    }

    // update the gameobject
    virtual void update(sf::Time dt) = 0;

protected:
    std::string name_;
};

#endif // SFMLSNAKE_GAMEOBJECT_HPP
