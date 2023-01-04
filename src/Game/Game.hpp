#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

class Game
{
public:
    // Constructor requires window width, height, and flags
    Game(const int &windowWidth, const int &windowHeight, const GLuint &flags);

    // Declare functions

    // Game loop
    void run();

    // Shutdown
    void quit();

private:
    // Variable definitions for window creation
    SDL_Window * mWindow;
    SDL_GLContext mContext;
    GLuint mWindowFlags;

    // Variable definition for SDL event handling
    SDL_Event mEvent;

    // Variable definitions for window name and sizing
    const char * mName = "Pong";
    int mWindowWidth;
    int mWindowHeight;

    // Is the game running?
    bool mRunning;
    
    // Create a new window
    void buildWindow();

    // Handle all SDL events
    void processInput();

    // Update all game objects
    void update();

    // Draw all objects
    void render();
};