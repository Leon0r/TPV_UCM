#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <fstream> // Para los archivos de entrada/salida

#include "GameCharacter.h"
class Game; // Evita llamadas circulares
const int ENERGY_VIT = 200;

class Pacman :
	public GameCharacter
{
private:
	Game* game = nullptr;

	int posIniX,
		posIniY,
		posActX,
		posActY;

	int dirX,
		dirY,
		dirNextX,
		dirNextY;

	int lifes;
	int energy = ENERGY_VIT;

public:
	Pacman();
	~Pacman();

	void Pacman::render();
	void Pacman::update();
	void Pacman::lessLife();
	void Pacman::nextDir(int newDirX, int newDirY);
	void Pacman::loadFromFile(ifstream& level, bool nuevo);
	void Pacman::saveToFile(ofstream& level);
};

