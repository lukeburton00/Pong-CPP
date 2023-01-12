#pragma once
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
    bool mIsRunning;
    float mDeltaTime;
    float mElapsedTime;
    Time mTime;

    GLuint mWidth, mHeight, mFlags;
    const char * mTitle;

    GameObject playerOne;
    GameObject playerTwo;

    void processInput();
    void update();
    void render();
};