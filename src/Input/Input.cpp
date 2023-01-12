#include "Input.hpp"

void Input::initialize()
{
	keyMap["W"] = SDL_SCANCODE_W;
	keyMap["A"] = SDL_SCANCODE_A;
	keyMap["S"] = SDL_SCANCODE_S;
	keyMap["D"] = SDL_SCANCODE_D;

	keyMap["UpArrow"] = SDL_SCANCODE_UP;
	keyMap["LeftArrow"] = SDL_SCANCODE_LEFT;
	keyMap["DownArrow"] = SDL_SCANCODE_DOWN;
	keyMap["RightArrow"] = SDL_SCANCODE_RIGHT;
}

void Input::processInput()
{
	SDL_PumpEvents();
}