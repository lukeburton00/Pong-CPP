#include <stdio.h>
#include "Game.hpp"

int main(int argc, char * argv[])
{
    // SDL2 Winow Flags
    GLuint flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

    // Game window size
    const int width = 640, height = 480;

    // Create instance of the game
    Game game(width, height, flags);

    // Start game loop
    game.run();

    // Exit
    return 0;
}