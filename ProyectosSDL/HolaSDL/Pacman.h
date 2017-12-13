#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <fstream> // Para los archivos de entrada/salida

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

