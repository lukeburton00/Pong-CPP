#pragma once
#include <string>
#include "Input.hpp"
#include "Window.hpp"
#include "Time.hpp"
#include "GameObject.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

class Game
{
public:
    void initialize();
    void run();
    void quit();

private:
    Input mInput;
    Window mWindow;
    bool mIsRunning;
    float mDeltaTime;
    float mElapsedTime;
    Time mTime;
    float reflectionPower;

    GLint64 mWidth, mHeight, mFlags;
    const char * mTitle;

    GameObject playerOne;
    GameObject playerTwo;
    GameObject ball;

    float paddleSpeed, ballSpeed;

    void processInput();
    void update();
    void render();

    void checkPlayerBounds();
    void checkBallBounds();
};