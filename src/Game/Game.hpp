#pragma once
#include <string>
#include "Input.hpp"
#include "Window.hpp"

class Game
{
public:

    void initialize();
    void run();
    void quit();

private:
    Input mInput;
    Window mWindow;
    bool mRunning;

    GLuint mWidth, mHeight, mFlags;
    const char * mTitle;

    void processInput();
    void update();
    void render();
};