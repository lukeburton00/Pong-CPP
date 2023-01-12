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
    paddle = Paddle(glm::vec2(0, 0), glm::vec2(1,1));

    mRenderer.prepareTriangle();
    mRenderer.prepareShaders();
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
}


void Game::render()
{
    mWindow.refresh();
    mRenderer.draw(mDeltaTime, paddle.mPosition.x, paddle.mPosition.y);
    mWindow.swapBuffers();
}