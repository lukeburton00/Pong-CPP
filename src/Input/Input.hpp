#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Input
{
	public:
		void processInput();
		bool isKeyPressed(const char * key);
		bool isKeyReleased(const char * key);
		bool quitEvent;

	private:
		SDL_Keycode keyCodeDown;
		std::vector<SDL_Keycode> pressedKeys;
		std::vector<SDL_Keycode> releasedKeys;
		SDL_Keycode keyCodeUp;
		SDL_Event event;
};