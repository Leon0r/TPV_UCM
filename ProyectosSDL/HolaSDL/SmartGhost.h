#pragma once
#include "Ghost.h"

const int ADULT_AGE = 40; // edad a partir de la cual son adultos
const int DEATH_AGE = 100; // edad a partir de la cual se mueren

class SmartGhost :
	public Ghost
{
private:
	int age = 0; // edad del fantasma
	bool dead = false; // a true cuando se muere

	par* targetPos = nullptr; // Posicion hacia la que se mueve

public:
	SmartGhost();
	SmartGhost(Game* game);

	virtual ~SmartGhost();

	virtual void update();
	// Lee los datos de archivo
	virtual void loadFromFile(ifstream& level);
	// Guarda en archivo
	virtual void saveToFile(ofstream& level);
	// Muerte "natural" de fantasma
	void dieOld(); 
	// Recibe la posicion hacia la que se tiene que mover
	void setTarget(par* posPacman) { targetPos = posPacman; };
	// De las dirs posibles, busca la que mas le acerque a Pacman
	void searchDir();
	
};

