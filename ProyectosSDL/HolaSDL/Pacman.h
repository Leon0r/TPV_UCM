#pragma once
#include "GameCharacter.h"

const int ENERGY_VIT = 200;
class Game;

class Pacman :
	public GameCharacter
{
private:

	par dirNext = { 0, 0 };

	int lifes,
		energy = ENERGY_VIT;

	bool switchAnim = false; // Cambio entre los dos frames de animaci�n


public:
	Pacman();
	Pacman(Game* game);

	virtual ~Pacman();

	// Actualiza el estado de PacMan (direcci�n y posici�n actual)
	virtual void update();

	void Pacman::checkCollisions();
	// Pierde una vida y vuelve a su posici�n inicial
	void lessLife();
	// Cambia el frame de la animaci�n seg�n su direcci�n
	void numFrameAnim();
	// Asigna a la siguiente posici�n los valores newDir
	void nextDir(int newDirX, int newDirY);
	// Carga de archivo la informaci�n del Pacman
	virtual void loadFromFile(ifstream& level);
	// Guarda en un archivo la informaci�n del Pacman
	virtual void saveToFile(ofstream& level);
	// Carga el pacman como tal
	void loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game);
	
};

