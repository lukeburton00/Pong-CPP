#include "Game.hpp"

Game::Game(const int &windowWidth, const int &windowHeight, const GLuint &flags)
{
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mWindowFlags = flags;
}

void Game::run()
{
    buildWindow();
    mRunning = true;

    //main loop
    while (mRunning)
    {
        processInput();
        update();
        render();
    }
}

void Game::quit()
{
    mRunning = false;
    printf("Game stopped.\n");
    SDL_DestroyWindow(mWindow);
    //Quit SDL subsystems
    SDL_GL_DeleteContext(mContext);
    SDL_Quit();
}

void Game::buildWindow()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL video could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    else
    {
        //Set OpenGL attributes for perfomance and compatibility
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        //Create window
        mWindow = SDL_CreateWindow( mName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWindowWidth, mWindowHeight, mWindowFlags);
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

void Game::processInput()
{
	while (SDL_PollEvent(&mEvent) != 0)
	{
		switch(mEvent.type)
		{
			case SDL_QUIT:
			{
				quit();
				break;
			}

			default:
			{
				break;
			}
		}
	}
}

void Game::update()
{

}

void Game::render()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(mWindow);
}
