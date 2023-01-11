#pragma once
#include <string>
#include "Input.hpp"
#include "Window.hpp"
#include "Paddle.hpp"
#include "Time.hpp"
#include "Renderer.hpp"

class Game
{
public:
    void initialize();
    void run();
    void quit();

private:
    Input mInput;
    Window mWindow;
    Renderer mRenderer;
    bool mIsRunning;
    float mDeltaTime;
    float mElapsedTime;
    Time mTime;

    GLuint mWidth, mHeight, mFlags;
    const char * mTitle;

    Paddle paddle;

    void processInput();
    void update();
    void render();
};