#include "global.hpp"
#include "game.hpp"

int main()
{
    Game *game = new Game(WIDTH, HEIGHT);
    game->run();
    delete game;
    return 0;
}