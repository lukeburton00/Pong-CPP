#include "Input.hpp"

void Input::processInput()
{
	releasedKeys.clear();
	while (SDL_PollEvent(&event) != 0)
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
			{
				keyCodeDown = event.key.keysym.sym;
				pressedKeys.push_back(keyCodeDown);
				break;
			}

			case SDL_KEYUP:
			{
				keyCodeUp = event.key.keysym.sym;
				pressedKeys.erase(remove(pressedKeys.begin(), pressedKeys.end(), keyCodeUp));
				releasedKeys.push_back(keyCodeUp);
				break;
			}

			case SDL_QUIT:
			{
				quitEvent = true;
				break;
			}

			default:
			{
				break;
			}
		}
	}
}

bool Input::isKeyPressed(const char * keyName)
{
    // Find key in pressed keys
    bool keyWasPressed = count(pressedKeys.begin(), pressedKeys.end(), SDL_GetKeyFromName(keyName));

	return keyWasPressed;
}

bool Input::isKeyReleased(const char * keyName)
{
    // Find key in released keys
    bool keyWasReleased = count(releasedKeys.begin(), releasedKeys.end(), SDL_GetKeyFromName(keyName));

	return keyWasReleased;
}