#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
class Window
{
public:
    void create(const int &windowWidth, const int &windowHeight, const char * title, const GLuint &flags);
    void refresh();
    void destroy();

private:
    int mWindowWidth;
    int mWindowHeight;
    GLuint mWindowFlags;
    SDL_Window * mWindow;
    SDL_GLContext mContext;

};