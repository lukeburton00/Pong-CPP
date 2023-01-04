#include <stdio.h>
#include "Game.hpp"

int main(int argc, char * argv[])
{
    GLuint flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
    const int width = 640, height = 480;

    Game game(width, height, flags);
    game.run();

    return 0;
}