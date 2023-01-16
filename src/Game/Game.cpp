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

    playerOne = Paddle(glm::vec3(-700, 0, 1), glm::vec3(20, 100, 0));
    playerOne.mMovementSpeed = 800;

    playerTwo = Paddle(glm::vec3(700, 0, 1), glm::vec3(20, 100, 0));
    playerTwo.mMovementSpeed = 800;

    ball = Ball(glm::vec3(0,0,0), glm::vec3(10,10,0));
    ball.mVelocity.x = -500;
    ball.mVelocity.y = 0;

    reflectionPower = 2;
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
    ball.mPosition += ball.mVelocity * mDeltaTime;

    checkPlayerBounds();
    checkBallBounds();
    checkWinCondition();

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
    ball.draw(mWidth, mHeight);
    mWindow.swapBuffers();
}

void Game::checkPlayerBounds()
{
    if ((playerOne.mPosition.y + playerOne.mScale.y) > mHeight)
    {
        playerOne.mPosition.y = mHeight - playerOne.mScale.y;
    }

    if ((playerOne.mPosition.y - playerOne.mScale.y) < -mHeight)
    {
        playerOne.mPosition.y = -mHeight + playerOne.mScale.y;
    }

    if ((playerTwo.mPosition.y + playerTwo.mScale.y) > mHeight)
    {
        playerTwo.mPosition.y = mHeight - playerTwo.mScale.y;
    }

    if ((playerTwo.mPosition.y - playerTwo.mScale.y) < -mHeight)
    {
        playerTwo.mPosition.y = -mHeight + playerTwo.mScale.y;
    }
}

void Game::checkBallBounds()
{
    bool ballCollidedWithPlayerOne = (ball.mPosition.x - ball.mScale.x <= (playerOne.mPosition.x + playerOne.mScale.x)) && ball.mPosition.x >= playerOne.mPosition.x && (ball.mPosition.y - ball.mScale.y > playerOne.mPosition.y - playerOne.mScale.y) && (ball.mPosition.y + ball.mScale.x < (playerOne.mPosition.y + playerOne.mScale.y));
    bool ballCollidedWithPlayerTwo = (ball.mPosition.x + ball.mScale.x >= (playerTwo.mPosition.x - playerTwo.mScale.x)) && ball.mPosition.x <= playerTwo.mPosition.x &&(ball.mPosition.y - ball.mScale.y > playerTwo.mPosition.y - playerTwo.mScale.y) && (ball.mPosition.y + ball.mScale.x < (playerTwo.mPosition.y + playerTwo.mScale.y));

    if (ball.mPosition.y + ball.mScale.y > mHeight)
    {
        ball.mVelocity.y *= -1;
    }

    if (ball.mPosition.y - ball.mScale.y < -mHeight)
    {
        ball.mVelocity.y *= -1;
    }

    if (ballCollidedWithPlayerOne)
    {
        ball.mVelocity.x *= -1;
        ball.mVelocity.y = ball.mPosition.y - playerOne.mPosition.y * reflectionPower;

        #ifdef DEBUG
        printf("Ball collided with player one.\n");
        #endif
    }

    if (ballCollidedWithPlayerTwo)
    {
        ball.mVelocity.x *= -1;
        ball.mVelocity.y = ball.mPosition.y - playerTwo.mPosition.y * reflectionPower;

        #ifdef DEBUG
        printf("Ball collided with player two.\n");
        #endif
    }
}

void Game::checkWinCondition()
{
    if (ball.mPosition.x > mWidth || ball.mPosition.x < -mWidth)
    {
        ball.mPosition = glm::vec3(0, 0, 0);
        playerOne.mPosition = glm::vec3(-700,0,0);
        playerTwo.mPosition = glm::vec3(700,0,0);

        ball.mVelocity.x *= -1;
        ball.mVelocity.y = 0;

        sleep(1);


    }
}

