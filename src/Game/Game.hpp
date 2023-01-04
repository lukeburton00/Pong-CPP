#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

class Game
{
public:
    Game(const int &windowWidth, const int &windowHeight, const GLuint &flags);

    void run();
    void quit();

private:
    SDL_Window * mWindow;
    SDL_GLContext mContext;
    SDL_Event mEvent;
    GLuint mWindowFlags;

    const char * mName = "Pong";
    int mWindowWidth;
    int mWindowHeight;
    bool mRunning;
    
    void buildWindow();

    void processInput();
    void update();
    void render();
};