#include "ingamescene.hpp"


InGameScene::InGameScene(std::uint8_t sizeX, std::uint8_t sizeY,
            std::string nameOfPlayer, sf::RenderWindow& window,
            Game& game) :
    Scene(window, game),
    boardSize_(sizeX, sizeY),
    nameOfPlayer_(nameOfPlayer),
    origin_(0,0),
    fieldSize_(0,0)
{
    // calculate the size of the view such that every field has the
    // size of sizeOfField
    const float borderSide          = 0.05;
    const float borderBottom        = 0.05;
    const float borderTop           = 0.1;
    const std::uint32_t sizeOfField = 20;

    const std::uint32_t boardPixelX = sizeOfField * sizeX;
    const std::uint32_t boardPixelY = sizeOfField * sizeY;

    const std::uint32_t offsetTop   = boardPixelY * borderTop;
    const std::uint32_t offsetBot   = boardPixelY * borderBottom;
    const std::uint32_t offsetSide  = boardPixelX * borderSide;


    // Set the view such that the board begins at (0,0) and
    // the borders around it are accounted for
    sf::View view(sf::FloatRect(-offsetTop, -offsetSide,
                sizeOfField * sizeX + offsetSide,
                sizeOfField * sizeY + offsetBot));
    window.setView();
}

void InGameScene::update(sf::Time dt) {
}

void InGameScene::handleInput() {
}
