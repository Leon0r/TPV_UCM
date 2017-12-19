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
	bool switchAnim = false; // Cambio entre los dos frames de animación

public:
	Pacman();
	~Pacman();

	// Dibuja el Pacman en su posición actual
	void Pacman::render();
	// Actualiza el estado de PacMan (dirección y posición actual)
	void Pacman::update();
	// Pierde una vida y vuelve a su posición inicial
	void Pacman::lessLife();
	// Cambia el frame de la animación según su dirección
	void Pacman::numFrameAnim();
	// Asigna a la siguiente posición los valores newDir
	void Pacman::nextDir(int newDirX, int newDirY);
	// Carga de archivo la información del Pacman
	void Pacman::loadFromFile(ifstream& level, bool nuevo);
	// Guarda en un archivo la información del Pacman
	void Pacman::saveToFile(ofstream& level);
	// Carga el pacman como tal
	void Pacman::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game);
};

