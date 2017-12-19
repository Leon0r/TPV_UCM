#include "Pacman.h"


Pacman::Pacman():GameCharacter()
{
}

Pacman::~Pacman()
{
}

// Dibuja el Pacman en su posición actual
void Pacman::render() {
	GameCharacter::render();
	rectDest.x = rectDest.w*posAct.x;
	rectDest.y = rectDest.h*posAct.y;
	numFrameAnim();

	texture->renderFrame(rectDest, frameRow, frameCol);
}

// Actualiza el estado de PacMan (dirección y posición actual)
void Pacman::update() {	
	// Memoria de dirección: solo cambia si es distinta a la que lleva y puede moverse hacia esa posición
	if ((dir.x != dirNext.x || dir.y != dirNext.y) && sigPosToroideEsLibre(dirNext)){
		dir.x = dirNext.x;
		dir.y = dirNext.y;
	}
	// Comprueba colisión entre fantasma-Pacman
	///TODO: game->collisionWithGhost()

	if (energy > 0)
		energy -= 1;

	/// NO SE SI ESTE IF ES NECESARIO POR EL NEXTCELL
	//if (lifes > 0 && game->nextCell(posAct.x, posAct.y, dir.x, dir.y))
	//{
		// Recarga energía al comerse una vitamina COMENTADO POR COMPILADO
	//if (game->cellEatable(posAct.x, posAct.y))
		//	energy = ENERGY_VIT;
	//}
}

// Pierde una vida y vuelve a su posición inicial
void Pacman::lessLife() {
	if (lifes > 0) {
		lifes--;
		posAct.x = posIni.x;
		posAct.y = posIni.y;
	}
}

// Cambia el frame de la animación según su dirección
void Pacman::numFrameAnim() {
	// Mira la fila del frame:
	if (dir.x == 1) // Derecha
		frameRow = 0;
	else if (dir.x == -1) // Izquierda
		frameRow = 2;
	else if (dir.y == 1) // Abajo
		frameRow = 1;
	else if (dir.y == -1) // Arriba
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
	dirNext.x = newDirX;
	dirNext.y = newDirY;
}

// Carga de archivo la información del Pacman
void Pacman::loadFromFile(ifstream& level, bool nuevo) {
	GameCharacter::loadFromFile(level);
	level >> posAct.x >> posAct.y >> dir.x >> dir.y >> energy >> lifes;
	if(!nuevo) // Si es un archivo de guardado lee también la energía y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la información del Pacman
void Pacman::saveToFile(ofstream& level) {
	GameCharacter::saveToFile(level);
	level << energy << " " << lifes;
}

void Pacman::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game) {
	loadCharacter(level, esqTextX, cellSize, texture, game);
}