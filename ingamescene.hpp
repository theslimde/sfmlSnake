#ifndef SFMLSNAKE_INGAMESCENE_HPP
#define SFMLSNAKE_INGAMESCENE_HPP

#include "scene.hpp"

class InGameScene : public Scene
{
public:
    InGameScene(unsigned short sizeX, unsigned short sizeY,
            std::string nameOfPlayer, sf::RenderWindow& window,
            Game& game);

};

#endif // SFMLSNAKE_INGAMESCENE_HPP
