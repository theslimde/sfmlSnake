#ifndef SFMLSNAKE_SCENE_HPP
#define SFMLSNAKE_SCENE_HPP

#include <memory>
#include <deque>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "gameobject.hpp"

class Game;

/*
 * A scene represents a stage within the game. It
 * handles input, drawing of its objects and updating of
 * its objects. A simple implementation is given.
 */
class Scene
{
public:

    Scene(sf::RenderWindow& window, Game& game) :
        window_(window),
        game_(game)
    {}

    // Virtual Dtor
    virtual ~Scene() {
    }

    // draw the scene
    virtual void draw();

    // update the scene
    // input dt : time passed since last update call
    virtual void update(sf::Time dt);

    // handle the input
    virtual void handleInput() = 0;

protected:
    // Use ptr to gameobjects in order to use inheritance.
    std::deque<std::unique_ptr<GameObject>> gameObjects_;

    sf::RenderWindow& window_;

    Game& game_;
};

#endif // SFMLSNAKE_SCENE_HPP
