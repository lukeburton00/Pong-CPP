#include "Game.hpp"

// Constructor sets the member variables for window creation
Game::Game(const int &windowWidth, const int &windowHeight, const GLuint &flags)
{
    // Set window width, height and flags
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mWindowFlags = flags;
}

// Game loop
void Game::run()
{
    // Create the window
    buildWindow();

    // Game is running
    mRunning = true;

    //main loop
    while (mRunning)
    {
        processInput();
        update();
        render();
    }
}

// Shut down the game
void Game::quit()
{
    // Stop the game loop
    mRunning = false;
    printf("Game stopped.\n");

    // Destroy the window
    SDL_DestroyWindow(mWindow);

    // Delete the OpenGL context
    SDL_GL_DeleteContext(mContext);

    //Quit SDL subsystems
    SDL_Quit();
}

// Build the window
void Game::buildWindow()
{
    // Start the SDL window subsystem
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL video could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    // if SDL window subsystem started successfully:
    else
    {
        // Set OpenGL attributes for perfomance and compatibility
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        // Create window
        mWindow = SDL_CreateWindow( mName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWindowWidth, mWindowHeight, mWindowFlags);
        if( mWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }

        // if SDL window created successfully:
        else
        {
            // Create OpenGL context
            mContext = SDL_GL_CreateContext(mWindow);
        }

        // initialize GLEW
        glewExperimental = GL_TRUE;
        glewInit();
    }
}

// Handle SDL input events
void Game::processInput()
{
    // Poll all events for this frame
	while (SDL_PollEvent(&mEvent) != 0)
	{
        // Check event type
		switch(mEvent.type)
		{
            // if window close requested
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

// Update all game objects
void Game::update()
{

}

// Draw all objects
void Game::render()
{
    // Clear the window and set background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    // Swap buffers
	SDL_GL_SwapWindow(mWindow);
}
