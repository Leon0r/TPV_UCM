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

void Pacman::loadFromFile(ifstream& level, bool nuevo) {
	GameCharacter::loadFromFile(level);

}

void Pacman::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << energy << " " << lifes;
}