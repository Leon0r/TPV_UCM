#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include "GameCharacter.h"

class Pacman :
	public GameCharacter
{
public:
	Pacman();
	~Pacman();

	void Pacman::render();
	void Pacman::loadFromFile();
	void Pacman::saveToFile();
};

