#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <fstream> // Para los archivos de entrada/salida

#include "GameCharacter.h"

const int ENERGY_VIT = 200;

class Pacman :
	public GameCharacter
{
private:
	int lifes;
	int energy = ENERGY_VIT;

public:
	Pacman();
	~Pacman();

	void Pacman::render();
	void Pacman::loadFromFile(ifstream& level, bool nuevo);
	void Pacman::saveToFile(ofstream& level);
};

