#include "Pacman.h"
#include "Game.h"

Pacman::Pacman() :GameCharacter(), lifes(0), energy(0), dirNext{0,0} {}

Pacman::Pacman(Game* game):GameCharacter(game) {
	type = 2;
}

Pacman::~Pacman()
{
}

// Actualiza el estado de PacMan (dirección y posición actual)
void Pacman::update() {	
	// Memoria de dirección: solo cambia si es distinta a la que lleva y puede moverse hacia esa posición
	if ((dir.x != dirNext.x || dir.y != dirNext.y) && sigPosToroideEsLibre(dirNext)){
		dir.x = dirNext.x;
		dir.y = dirNext.y;
	}
	
	checkCollisions();
	
	if (energy > 0)
		energy -= 1;

	// Recarga energía al comerse una vitamina
	if (game->cellEatable(posAct.x, posAct.y))
		energy = ENERGY_VIT;
	GameCharacter::update();
}

void Pacman::checkCollisions() {

	list <GameCharacter*>::iterator it;
	if (game->isAGhost(posAct.x + dirNext.x, posAct.y + dirNext.y, it) && energy == 0)
		lessLife();

	if (game->isAGhost(posAct.x + dirNext.x, posAct.y + dirNext.y, it) && energy > 0)
		(*it)->die();
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
		frame.y = 0;
	else if (dir.x == -1) // Izquierda
		frame.y = 2;
	else if (dir.y == 1) // Abajo
		frame.y = 1;
	else if (dir.y == -1) // Arriba
		frame.y = 3;

	// Mira la columna, la cambia para que haya movimiento
	if (switchAnim)
		frame.x = 10;
	else
		frame.x = 11;

	// Abrir/cerrar la boca
	switchAnim = !switchAnim; // En la siguiente vuelta se invierte
}

// Asigna a la siguiente posición los valores newDir
void Pacman::nextDir(int newDirX, int newDirY) {
	dirNext.x = newDirX;
	dirNext.y = newDirY;
}

// Carga de archivo la información del Pacman
void Pacman::loadFromFile(ifstream& level) {
	GameCharacter::loadFromFile(level);
	if(!level.eof()) // Si es un archivo de guardado lee también la energía y las vidas
		level >> energy >> lifes;
}

// Guarda en un archivo la información del Pacman
void Pacman::saveToFile(ofstream& level) {
	level << energy << " " << lifes;
}

// Carga el pacman como tal
void Pacman::loadCharacter(ifstream& level, int esqTextX, int cellSize, Textures * texture, Game* game) {
	GameCharacter::loadCharacter(level, esqTextX, cellSize, texture, game);
}