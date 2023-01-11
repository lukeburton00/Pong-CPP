#pragma once
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <chrono>

using chronoTime = std::chrono::high_resolution_clock;
using timePoint = std::chrono::high_resolution_clock::time_point;
class Time
{
public:

    void start();
    void stop();

    float getElapsedTime();

private:
    bool mIsStarted;
    timePoint mStartTime;
    timePoint mStopTime;
    float mElapsedTime;
};