#include "Game.hpp"


void Game::initialize()
{
    printf("Initializing Game...\n");
    mWidth = 640;
    mHeight = 480;
    mFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
    mTitle = "Performance Test";
    mWindow.create(mWidth, mHeight, mTitle, mFlags);
    mInput.initialize();
    paddle = Paddle(glm::vec2(200, 100), glm::vec2(1,1));
}

void Game::run()
{
    printf("Running Game...\n");
    mElapsedTime = 0.0f;
    mIsRunning = true;

    #ifdef DEBUG
    int frames = 0;
    int frames_per_second = 0;
    #endif
    while (mIsRunning)
    {
        mDeltaTime = 0;
        mTime.start();
        processInput();
        update();
        render();

        mTime.stop();
        mDeltaTime = mTime.getElapsedTime();

        #ifdef DEBUG
        frames++;
        mElapsedTime += mDeltaTime;

        
        if (mElapsedTime >= 1)
        {
            frames_per_second = frames/mElapsedTime;
            std::cout << "frames per second: " << frames_per_second << std::endl;
            mElapsedTime = 0;
            frames = 0;
        }
        #endif
    }
    
}

void Game::quit()
{
    mIsRunning = false;
    mWindow.destroy();
    printf("Game stopped.\n");
}

void Game::processInput()
{
    mInput.processInput();
    if (mInput.quitEvent) mIsRunning = false;
}

void Game::update()
{
    const Uint8 * keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
        return;
    }

    if (keys[mInput.keyMap["W"]])
    {
        paddle.mPosition.y += 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["A"]])
    {
        paddle.mPosition.x -= 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["S"]])
    {
        paddle.mPosition.y -= 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["D"]])
    {
        paddle.mPosition.x += 1 * mDeltaTime;
    }

    //std::cout << "Paddle X: " << paddle.mPosition.x << std::endl;
    //std::cout << "Paddle Y: " << paddle.mPosition.y << std::endl;
}


void Game::render()
{
    mWindow.refresh();
}