#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <map>

class Input
{
	public:
		void initialize();
		void processInput();
		bool quitEvent;
		std::map<std::string, SDL_Scancode> keyMap;
};