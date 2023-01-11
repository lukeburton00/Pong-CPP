#include "Time.hpp"

void Time::start()
{
    mIsStarted = true;
    mStartTime = chronoTime::now();
}

void Time::stop()
{
    if (!mIsStarted)
    {
        printf("ERROR: Time::stop called without starting the timer.\n");
        return;
    }
    mIsStarted = false;
    mStopTime = chronoTime::now();
    std::chrono::duration<float> elapsed = mStopTime - mStartTime;
    mElapsedTime = elapsed.count();
}

float Time::getElapsedTime()
{
    return mElapsedTime;
}