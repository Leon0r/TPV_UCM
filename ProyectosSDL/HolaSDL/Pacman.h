#pragma once
#include "checkML.h"
#include "SDL.h"
#include "SDL_image.h"
#include <fstream> // Para los archivos de entrada/salida
#include "GameCharacter.h"
//#include "GameMap.h"

const int ENERGY_VIT = 200;
class Game;

class Pacman :
	public GameCharacter
{
private:
	
	par dirNext;

	int lifes,
		energy = ENERGY_VIT;

	bool switchAnim = false; // Cambio entre los dos frames de animación


public:
	Pacman();
	Pacman(Game* game);

	virtual ~Pacman();

	// Actualiza el estado de PacMan (dirección y posición actual)
	virtual void update();
	// Pierde una vida y vuelve a su posición inicial
	void lessLife();
	// Cambia el frame de la animación según su dirección
	void numFrameAnim();
	// Asigna a la siguiente posición los valores newDir
	void nextDir(int newDirX, int newDirY);
	// Carga de archivo la información del Pacman
	virtual void loadFromFile(ifstream& level);
	// Guarda en un archivo la información del Pacman
	virtual void saveToFile(ofstream& level);
	// Carga el pacman como tal
	void loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game);
};

