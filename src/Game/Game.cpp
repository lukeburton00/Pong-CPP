#include "Game.hpp"


void Game::initialize()
{
    #ifdef DEBUG
    printf("Initializing Game...\n");
    #endif

    #ifdef RELEASE
    printf("Running game in release mode. Enjoy!\n");
    #endif

    mWidth = 800;
    mHeight = 600;
    mFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

    #ifdef DEBUG
    mTitle = "DEBUG";
    #endif

    #ifdef RELEASE
    mTitle = "Pong";
    #endif

    mWindow.create(mWidth, mHeight, mTitle, mFlags);
    mInput.initialize();

    playerOne = GameObject(glm::vec3(-30, 0, 1), glm::vec3(20, 100, 1));
    playerOne.mMovementSpeed = 20;

    playerTwo = GameObject(glm::vec3(30, 0, 1), glm::vec3(20, 100, 1));
    playerTwo.mMovementSpeed = playerOne.mMovementSpeed;
}

void Game::run()
{
    #ifdef DEBUG
    printf("Running Game...\n\n");
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
            std::cout << "Rolling FPS: " << frames_per_second << std::endl;
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
        playerOne.mPosition.y += playerOne.mMovementSpeed * mDeltaTime;
    }
    
    if (keys[mInput.keyMap["S"]])
    {
        playerOne.mPosition.y -= playerOne.mMovementSpeed  * mDeltaTime;
    }

    if (keys[mInput.keyMap["UpArrow"]])
    {
        playerTwo.mPosition.y += playerTwo.mMovementSpeed * mDeltaTime;
    }

    if (keys[mInput.keyMap["DownArrow"]])
    {
        playerTwo.mPosition.y -= playerTwo.mMovementSpeed  * mDeltaTime;
    }
}


void Game::render()
{
    mWindow.refresh();
    playerOne.draw(mWidth, mHeight);
    playerTwo.draw(mWidth, mHeight);
    mWindow.swapBuffers();
}