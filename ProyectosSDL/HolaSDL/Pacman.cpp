#include "Pacman.h"
#include "game.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

// Dibuja el Pacman en su posici�n actual
void Pacman::render() {
	GameCharacter::render();
	rectDest.x = rectDest.w*posActX;
	rectDest.y = rectDest.h*posActY;
	numFrameAnim();

	texture->renderFrame(rectDest, frameRow, frameCol);
}

// Actualiza el estado de PacMan (direcci�n y posici�n actual)
void Pacman::update() {	
	// Memoria de direcci�n: solo cambia si es distinta a la que lleva y puede moverse hacia esa posici�n
	if ((dirX != dirNextX || dirY != dirNextY) && game->nextCell(posActX, posActY, dirNextX, dirNextY)){
		dirX = dirNextX;
		dirY = dirNextY;
	}
	// Comprueba colisi�n entre fantasma-Pacman
	///TODO: game->collisionWithGhost()

	if (energy > 0)
		energy -= 1;

	if (lifes > 0 && game->nextCell(posActX, posActY, dirX, dirY))
	{
		///TODO: toroide
		///TODO: comer energ�a sube la energ�a
	}
}

// Pierde una vida y vuelve a su posici�n inicial
void Pacman::lessLife() {
	if (lifes > 0) {
		lifes--;
		posActX = posIniX;
		posActY = posIniY;
	}
}

// Cambia el frame de la animaci�n seg�n su direcci�n
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

// Asigna a la siguiente posici�n los valores newDir
void Pacman::nextDir(int newDirX, int newDirY) {
	dirNextX = newDirX;
	dirNextY = newDirY;
}

// Carga de archivo la informaci�n del Pacman
void Pacman::loadFromFile(ifstream& level, bool nuevo) {
	GameCharacter::loadFromFile(level);
	level >> posActX >> posActY >> dirX >> dirY >> energy >> lifes;
	if(!nuevo) // Si es un archivo de guardado lee tambi�n la energ�a y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la informaci�n del Pacman
void Pacman::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << energy << " " << lifes;
}