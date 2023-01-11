#include "Window.hpp"

void Window::create(const int &windowWidth, const int &windowHeight, const char * title, const GLuint &flags)
{
    printf("Creating window...\n");
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mWindowFlags = flags;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL video could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    else
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        mWindow = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWindowWidth, mWindowHeight, mWindowFlags);
        if( mWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }

        else
        {
            mContext = SDL_GL_CreateContext(mWindow);
        }

        glewExperimental = GL_TRUE;
        glewInit();
    }
}

void Window::refresh()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

}

void Window::swapBuffers()
{
	SDL_GL_SwapWindow(mWindow);
}

void Window::destroy()
{
    printf("Destroying Window...\n");
    SDL_DestroyWindow(mWindow);
    SDL_GL_DeleteContext(mContext);
}