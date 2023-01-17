#pragma once
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <string>
#include "Input.hpp"
#include "Window.hpp"
#include "Time.hpp"
#include "GameObject.hpp"
class Game
{
public:
    void initialize();
    void run();
    void quit();

private:
    Input mInput;
    Window mWindow;
    Time mTime;

    GLint64 mWidth, mHeight, mFlags;
    const char * mTitle;

    bool mIsRunning;
    float mDeltaTime;
    float mElapsedTime;
    
    GameObject playerOne;
    GameObject playerTwo;
    GameObject ball;

    float reflectionPower;
    float previousServe;

    void processInput();
    void update();
    void render();

    void checkPlayerBounds();
    void checkBallBounds();
    void checkWinCondition();
};