#include "Input.hpp"

void Input::initialize()
{
	keyMap["W"] = SDL_SCANCODE_W;
	keyMap["A"] = SDL_SCANCODE_A;
	keyMap["S"] = SDL_SCANCODE_S;
	keyMap["D"] = SDL_SCANCODE_D;
}

void Input::processInput()
{
	SDL_PumpEvents();
}