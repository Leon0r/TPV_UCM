#include "Game.h"
#include "Pacman.h"

Game::Game()
{
}


Game::~Game()
{
}

// Bucle principal del juego
void Game::run() {
	
	while (!exit) {
		
	}
}

// Se encarga de los eventos de teclado
void Game::handleEvents() {
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			exit = true;
		// Eventos de felchas de dirección
		else if (event.key.keysym.sym == SDLK_UP)
			pacman->nextDir(0, -1);
		else if (event.key.keysym.sym == SDLK_DOWN)
			pacman->nextDir(0, 1);
		else if (event.key.keysym.sym == SDLK_LEFT)
			pacman->nextDir(-1, 0);
		else if (event.key.keysym.sym == SDLK_RIGHT)
			pacman->nextDir(-1, 0);			
	}
}

// Devuelve true si la sig casilla en direccion dir es vacia
// El 1 es muro
bool Game::nextCell(int posX, int posY, const int dirX, const int dirY) {
	int auxX = posX;
	int auxY = posY;
	nextPosToroide(auxX, auxY, dirX, dirY);
	return (map->getCellType(auxY, auxX) != 1);
}

// Calcula la sig pos (con toroide)
void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY) {
	if (dirX == -1)
		Left(posX);
	else if (dirX == 1)
		Right(posX);
	else if (dirY == -1)
		Up(posY);
	else if (dirY == 1)
		Down(posY);

}

// Consulta si la casilla es comestible: comida o energía, en el segundo caso devuelve true
bool Game::cellEatable(const int x, const int y) {
	bool vit = map->getCellType(y, x) == 3; // Vitamina hace que devuelva true la función
	if (map->getCellType(y, x) == 3 || map->getCellType(y, x) == 2) { // 3: vitamina, 2: comida
		foodLeft--; // Resta a la comida total
		map->fillCell(y, x, 0); // Cambia la casilla a vacío
	}
	return vit;
}

// Mira si en hay fantasma en la pos (x,y)
void Game::collisionWithGhost(int x, int y) {
	bool crush = false;
	/// TODO: Bucle que recorre los fantasmas para saber sus posiciones actuales
	/// TODO: crush se pone a true si la posicion de algún fantasma coincide con x && y

	/// ESTO HABRÍA QUE SACARLO A GHOST Y PACMAN??
	/// TODO: si crush es true y pacman tiene vitamina, ghost muere, si no pacman pierde vida
}

// Metodos auxiliares para calcular la sig pos teniendo en cuenta el toroide
void Game::Up(int& posY) {
	if (posY - 1 < 0)
		posY = map->getNumRow() - 1;
	else
		posY = posY - 1;
}

void Game::Down(int& posY) {
	if (posY + 1 >= map->getNumRow())
		posY = 0;
	else
		posY = posY + 1;
}

void Game::Left(int& posX) {
	if (posX - 1 < 0)
		posX = map->getNumCols() - 1;
	else
		posX = posX - 1;
}

void Game::Right(int& posX) {
	if (posX + 1 >= map->getNumCols())
		posX = 0;
	else
		posX = posX + 1;
}