#include "Pacman.h"
#include "game.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

void Pacman::render() {
	GameCharacter::render();
	rectDest.x = rectDest.w*posActX;
	rectDest.y = rectDest.h*posActY;
	numFrameAnim();
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

void Pacman::numFrameAnim() {
	// Mira la fila del frame:
	if (dirX == 1) // Derecha
		frameRow = 0;
	else if (dirX == -1) // Izquierda
		frameRow = 2;
	else if (dirY == 1) // Abajo
		frameRow = 1;
	else if (dirY == -1) // Arriba
		frameRow = 3;

	// Mira la columna, la cambia para que haya movimiento
	if (switchAnim)
		frameCol = 10;
	else
		frameCol = 11;

	// Abrir/cerrar la boca
	switchAnim = !switchAnim; // En la siguiente vuelta se invierte
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