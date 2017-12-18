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

	int lifes,
		energy = ENERGY_VIT;

	// Para las animaciones
	int frameRow, frameCol;
	bool switchAnim = false; // Cambio entre los dos frames de animación


public:
	Pacman();
	~Pacman();

	void Pacman::render();
	void Pacman::update();
	void Pacman::numFrameAnim();
	void Pacman::lessLife();
	void Pacman::nextDir(int newDirX, int newDirY);
	void Pacman::loadFromFile(ifstream& level, bool nuevo);
	void Pacman::saveToFile(ofstream& level);
};

