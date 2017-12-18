#include "Pacman.h"



Pacman::Pacman()
{
}


Pacman::~Pacman()
{
}

void Pacman::render() {
	GameCharacter::render();
}

void Pacman::update() {	
}

// Pierde una vida y vuelve a su posición inicial
void Pacman::lessLife() {
	if (lifes > 0) {
		lifes--;
		posActX = posIniX;
		posActY = posIniY;
	}
}

// Asigna a la siguiente posición los valores newDir
void Pacman::nextDir(int newDirX, int newDirY) {
	dirNextX = newDirX;
	dirNextY = newDirY;
}

void Pacman::loadFromFile(ifstream& level, bool nuevo) {
	GameCharacter::loadFromFile(level);

}

void Pacman::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << energy << " " << lifes;
}