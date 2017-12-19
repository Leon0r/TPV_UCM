#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <fstream> // Para los archivos de entrada/salida
#include "GameCharacter.h"
//#include "GameMap.h"

const int ENERGY_VIT = 200;

class Pacman :
	public GameCharacter
{
private:
	
	par dirNext;
	int dirNextX,
		dirNextY;

	int lifes,
		energy = ENERGY_VIT;

	// Para las animaciones
	int frameRow, frameCol;
	bool switchAnim = false; // Cambio entre los dos frames de animaci�n

public:
	Pacman();
	~Pacman();

	// Dibuja el Pacman en su posici�n actual
	void Pacman::render();
	// Actualiza el estado de PacMan (direcci�n y posici�n actual)
	void Pacman::update();
	// Pierde una vida y vuelve a su posici�n inicial
	void Pacman::lessLife();
	// Cambia el frame de la animaci�n seg�n su direcci�n
	void Pacman::numFrameAnim();
	// Asigna a la siguiente posici�n los valores newDir
	void Pacman::nextDir(int newDirX, int newDirY);
	// Carga de archivo la informaci�n del Pacman
	void Pacman::loadFromFile(ifstream& level, bool nuevo);
	// Guarda en un archivo la informaci�n del Pacman
	void Pacman::saveToFile(ofstream& level);
	// Carga el pacman como tal
	void Pacman::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game);
};

