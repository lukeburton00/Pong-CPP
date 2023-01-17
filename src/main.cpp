#define SDL_MAIN_HANDLED
#include <stdio.h>
#include "Game.hpp"
#include <iostream>

int main(int argc, char * argv[])
{
    // Initialize game
    Game game;
    game.initialize();

    // Start game
    game.run();

    // Exit
    return 0;
}