#include "Game.hpp"


void Game::initialize()
{
    #ifdef DEBUG
    printf("Initializing Game...\n");
    #endif

    mWidth = 640;
    mHeight = 480;
    mFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
    mTitle = "Performance Test";

    mWindow.create(mWidth, mHeight, mTitle, mFlags);
    mInput.initialize();

    playerOne = GameObject(glm::vec3(-0.8, 0, 0), glm::vec3(0.4, 3, 1));

    playerTwo = GameObject(glm::vec3(0.8, 0, 0), glm::vec3(0.4,3,1));
}

void Game::run()
{
    #ifdef DEBUG
    printf("Running Game...\n");
    int frames = 0;
    int frames_per_second = 0;
    #endif

    mElapsedTime = 0.0f;
    mIsRunning = true;
    while (mIsRunning)
    {
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
    mWindow.destroy();

    #ifdef DEBUG
    printf("Game stopped.\n");
    #endif
    mIsRunning = false;
}

void Game::processInput()
{
    mInput.processInput();

    if (mInput.quitEvent)
    {
        quit();
    }
} 

void Game::update()
{

    const Uint8 * keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_ESCAPE])
    {
        quit();
        return;
    }

    if (keys[mInput.keyMap["W"]])
    {
        playerOne.mPosition.y += 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["S"]])
    {
        playerOne.mPosition.y -= 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["UpArrow"]])
    {
        playerTwo.mPosition.y += 1 * mDeltaTime;
    }

    if (keys[mInput.keyMap["DownArrow"]])
    {
        playerTwo.mPosition.y -= 1 * mDeltaTime;
    }
}


void Game::render()
{
    mWindow.refresh();
    playerOne.draw();
    playerTwo.draw();
    mWindow.swapBuffers();
}