#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Ghost.h"

class SmartGhost :
	public Ghost
{
public:
	SmartGhost();
	~SmartGhost();

	void SmartGhost::update();
	void SmartGhost::loadFromFile(ifstream& level);
	void SmartGhost::saveToFile(ofstream& level);
};

