#include "ingamescene.hpp"

InGameScene::InGameScene(unsigned short sizeX, unsigned short sizeY,
            std::string nameOfPlayer, sf::RenderWindow& window,
            Game& game) :
    Scene(window, game),
    sizeX_(sizeX),
    sizeY_(sizeY),
    nameOfPlayer_(nameOfPlayer)
{
    // get the size of the window and calculate the size of the fields
    sf::Vector2u windowSize = window.getSize();
    std::
}
