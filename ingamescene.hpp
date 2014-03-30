#ifndef SFMLSNAKE_INGAMESCENE_HPP
#define SFMLSNAKE_INGAMESCENE_HPP

#include <cstdint>
#include <string>

#include <SFML/System/Vector2.hpp>

#include "scene.hpp"

class InGameScene : public Scene
{
public:
    InGameScene(std::uint8_t sizeX, std::uint8_t sizeY,
            std::string nameOfPlayer, sf::RenderWindow& window,
            Game& game);

    virtual ~InGameScene() {
    }

    virtual void update(sf::Time dt) override;

    virtual void handleInput() override;

private:

    sf::Vector2u boardSize_;
    std::string  nameOfPlayer_;
    sf::Vector2u origin_;
    sf::Vector2u fieldSize_;
};

#endif // SFMLSNAKE_INGAMESCENE_HPP
