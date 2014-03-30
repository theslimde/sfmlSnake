#ifndef SFMLSNAKE_GAME_HPP
#define SFMLSNAKE_GAME_HPP

#include <memory>

#include "scene.hpp"

/*
 * The Game class is coordinating the whole game. It is
 * somewhat of a miniature game engine supporting scenes
 * and game objects.
 */
class Game
{
public:

    Game();

    // Run the game. Returns a posix compliant error message,
    // i.e. 0 for success and -1 if an error occured.
    int run();

    // stop the game
    void exit();

    // set a new scene. This also deletes the current scene
    void setScene(std::unique_ptr<Scene> scene);

private:


    // Use ptr to scenes in order to use inheritance.
    std::unique_ptr<Scene> scene_;

    // Is the game running?
    bool running_ = false;
};

#endif // SFMLSNAKE_GAME_HPP
