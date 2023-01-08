#include "Game.hpp"

void Game::initialize()
{
    printf("Initializing Game...\n");
    mWidth = 640;
    mHeight = 480;
    mFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
    mTitle = "Ohheythere";
    mWindow.create(mWidth, mHeight, mTitle, mFlags);
    paddle = Paddle(glm::vec2(200, 100), glm::vec2(1,1));
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
        return;
    }

    if (mInput.isKeyPressed("W"))
    {
        paddle.mPosition.y += 1;
    }

    if (mInput.isKeyPressed("A"))
    {
       paddle.mPosition.x -= 1;
    }

    if (mInput.isKeyPressed("S"))
    {
        paddle.mPosition.y -= 1;
    }

    if (mInput.isKeyPressed("D"))
    {
        paddle.mPosition.x += 1;
    }

    std::cout << "Paddle X: " << paddle.mPosition.x << std::endl;
    std::cout << "Paddle Y: " << paddle.mPosition.y << std::endl;
}

void Game::render()
{
    mWindow.refresh();
}