#include "Game.hpp"

void Game::initialize()
{
    printf("Initializing Game...\n");
    mWidth = 640;
    mHeight = 480;
    mFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
    mTitle = "Ohheythere";
    mWindow.create(mWidth, mHeight, mTitle, mFlags);
}

void Game::run()
{
    printf("Running Game...\n");
    mRunning = true;

    while (mRunning)
    {
        processInput();
        update();
        render();
    }
}

void Game::quit()
{
    mRunning = false;
    mWindow.destroy();
    printf("Game stopped.\n");
}

void Game::processInput()
{
    mInput.processInput();
}

void Game::update()
{
    if (mInput.isKeyPressed("Escape"))
    {
        printf("Escape pressed.\n");
        quit();
    }

    if (mInput.isKeyReleased("W"))
    {
        printf("W released.\n");
    }

    if (mInput.isKeyReleased("S"))
    {
        printf("S released.\n");
    }

    if (mInput.isKeyPressed("A"))
    {
        printf("A pressed.\n");
    }
}

void Game::render()
{
    mWindow.refresh();
}