#include "Pacman.h"
#include "game.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

// Dibuja el Pacman en su posición actual
void Pacman::render() {
	GameCharacter::render();
	rectDest.x = rectDest.w*posActX;
	rectDest.y = rectDest.h*posActY;
	numFrameAnim();

	texture->renderFrame(rectDest, frameRow, frameCol);
}

// Actualiza el estado de PacMan (dirección y posición actual)
void Pacman::update() {	
	// Memoria de dirección: solo cambia si es distinta a la que lleva y puede moverse hacia esa posición
	if ((dirX != dirNextX || dirY != dirNextY) && game->nextCell(posActX, posActY, dirNextX, dirNextY)){
		dirX = dirNextX;
		dirY = dirNextY;
	}
	// Comprueba colisión entre fantasma-Pacman
	///TODO: game->collisionWithGhost()

	if (energy > 0)
		energy -= 1;

	if (lifes > 0 && game->nextCell(posActX, posActY, dirX, dirY))
	{
		///TODO: toroide
		///TODO: comer energía sube la energía
	}
}

// Pierde una vida y vuelve a su posición inicial
void Pacman::lessLife() {
	if (lifes > 0) {
		lifes--;
		posActX = posIniX;
		posActY = posIniY;
	}
}

// Cambia el frame de la animación según su dirección
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

// Carga de archivo la información del Pacman
void Pacman::loadFromFile(ifstream& level, bool nuevo) {
	GameCharacter::loadFromFile(level);
	level >> posActX >> posActY >> dirX >> dirY >> energy >> lifes;
	if(!nuevo) // Si es un archivo de guardado lee también la energía y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la información del Pacman
void Pacman::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << energy << " " << lifes;
}