#define SDL_MAIN_HANDLED
#include <stdio.h>
#include "Game.hpp"
#include <iostream>

int main(int argc, char * argv[])
{
    Game game;
    game.initialize();

    // Start game loop
    game.run();

    // Exit
    return 0;
}