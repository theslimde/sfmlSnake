#include "game.hpp"
#include "ingamescene.hpp"

int main(int argc, char** argv)
{
    Game game;
    std::unique_ptr<InGameScene> start(new InGameScene(40,30,"Player",
                game.getWindow(), game));

    game.setScene(std::move(start));

    return game.run();
}
